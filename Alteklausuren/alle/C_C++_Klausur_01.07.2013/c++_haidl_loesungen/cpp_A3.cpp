// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

#include <iostream>
#include <sstream>
#include "test.h"
#include "ident.h"
using namespace std;

// Ihr code 
#include "cpp_A3.hpp"

int main()
{   
    StartTest("C++",3);

    // todo: folgenden Code einkommentieren, wenn Funktionalität verfügbar
   
    stringset s1;
    Assert1( 0, 0==s1.v.size() );

    s1.add("Dies");
    Assert1( 1, 1==s1.v.size() && s1.v[0]=="Dies" );

    (s1 += ("ist")) +=("Dies");
    Assert1( 2, 2==s1.v.size() && s1.v[0]=="Dies" && s1.v[1]=="ist");

    stringset s2=s1;
    Assert1( 3, 2==s2.v.size() && s2.v[0]=="Dies" && s2.v[1]=="ist");
    
    stringset s3 { "ist", "ein", "Test!", "ist" };
    Assert1( 4, 3==s3.v.size() && s3.v[0]=="ist" && s3.v[1]=="ein" && s3.v[2]=="Test!");
    
    stringset s4;
    s4 = s1 + s3; 
    Assert1( 5, 4==s4.v.size() && s4.v[0]=="Dies" && s4.v[1]=="ist" && s4.v[2]=="ein" && s4.v[3]=="Test!");
    
    const stringset & s5 = s4;
    const string & s = s5[3];
	Assert1( 6, s=="Test!");
    
    stringstream sstr1;
    sstr1 << s4;
    Assert1( 7, sstr1.str()=="{ 'Dies' 'ist' 'ein' 'Test!' }");
    
    stringstream sstr2;
    for (string  s : s4)
		sstr2 << s;
    Assert1( 8, sstr2.str()=="DiesisteinTest!");
    
    Tset<int> t1;
    for (int i=1; i<10; ++i)
		t1 += (i % 3);
    Assert1( 9, 3==t1.v.size() && t1.v[0]==1 && t1.v[1]==2 && t1.v[2]==0);
    
    StopTest();
    
    return EXIT_SUCCESS;
}
