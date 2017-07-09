#include "test.h"
#include "A4.hpp"

#ifdef A4_a
// Global
add_formel p;
#endif


bool test_A4_a() {
#ifdef A4_a
    return (p.v.size() == 0);
#else
    return false;
#endif
}

int x2(int x) { return 2*x*x; }

bool test_A4_b() {
#ifdef A4_b
    // 2+3*n+2*n*n => p(1)=7, p(-2)=4
    p += [](int)   { return 2;   };
    p += [](int n) { return 3*n; };
    p += x2;
    return p.v.size()==3;
#else
    return false;
#endif
}

bool test_A4_c() {
#ifdef A4_c
    return (p.eval(1)==7 && p.eval(-2)==4);
#else
    return false;
#endif
}

bool test_A4_d() {
#ifdef A4_d
    return (p(1)==7 && p(-2)==4);
#else
    return false;
#endif
}

int main() {
    StartTest("C++",4);
	AssertS("a) polynom p definiert   ",  test_A4_a() );
	AssertS("b) Funktionen hinzugefügt",  test_A4_b() );
	AssertS("c) Eval getestet         ",  test_A4_c() );
	AssertS("d) Op() getestet         ",  test_A4_d() );
    StopTest();
    return EXIT_SUCCESS;
}
