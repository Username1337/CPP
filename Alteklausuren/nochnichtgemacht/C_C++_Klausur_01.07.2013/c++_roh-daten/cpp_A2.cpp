// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

#include <iostream>
#include <memory>
#include <vector>
#include "test.h"
#include "ident.h"
using namespace std;

// Ihr code 
#include "cpp_A2.hpp"

// test cases (tc)
// Aufbau: Nr., erwarteter Rückgabewert
const struct { unsigned int no; unsigned int expected; } tc[] = {
    {  1,  6 },
    {  2, 10 },
    {  3,  8 },
    {  4,  9 },
    {  5,  2 },
    {  6, 12 },
    {  7,  7 },
    {  8,  3 },
    {  9,  5 },
    { 10,  4 },
    { 11, 11 },
    { 12,  1 },
}; 
const size_t tc_count = sizeof(tc)/sizeof(tc[0]);

unsigned int next_random_number(unsigned int n) { return (6*n+0) % 13; }

int main()
{   
    StartTest("C++",2);

    vector<PRNG_Base*> G;
    
    // todo: folgende ptr einkommentieren, wenn Klasse verfügbar
    
    // G.push_back( new LKG(6,0,13,1) );
    // G.push_back( new PRNG(1,next_random_number) );
    // G.push_back( new PRNG(1,/* lambda todo */) );

    for (size_t k=0; k<G.size(); ++k)
    { 
        // todo: folgenden Code einkommentieren, wenn Funktionen verfügbar
        
        // jeweils alle Testfälle

        // for (size_t i=0; i<tc_count; ++i) 
        //     Assert2(k,i, tc[i].expected==G[k]->next() );
        
        // unique_ptr<unsigned int[]> sequence( G[k]->generate_seq(tc_count) );
        // for (size_t i=0; i<tc_count; ++i) 
        //     Assert2(k,i+tc_count, tc[i].expected==sequence[i] );
    }
    
    for (auto prng : G)
        delete prng;

    StopTest();
    
    return EXIT_SUCCESS;
}
