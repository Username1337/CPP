// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

#include <iostream>
#include <cmath>
#include "test.h"
#include "ident.h"
using namespace std;

// Ihr code 
#include "cpp_A1.hpp"

// test cases (tc)
// Aufbau: Zahl, erwarteter Rückgabewert
const struct { unsigned int n; unsigned int expected; } tc[] = {
    {     2,     1 },
    {     6,     6 },
    {    28,    28 },
    {   496,   496 },
    {    10,     8 },
    {    12,    16 },
    {   945,   975 },
    {    86,    46 },
    { 99971,     1 },
    {908209,   954 },
    {    17,     1 },
    {    3,      1 },
    {    1,      0 },
}; 
const size_t tc_count = sizeof(tc)/sizeof(tc[0]);

int main()
{   
    StartTest("C++",1);

    // alle Testfälle
    for (size_t i=0; i<tc_count; ++i) 
    {
        Assert2(i, 0, sum_factors_serial(tc[i].n)   == tc[i].expected );
        Assert2(i, 1, sum_factors_parallel(tc[i].n) == tc[i].expected );
    }

    StopTest();
    
    return EXIT_SUCCESS;
}
