#include "test.h"
#include "A3.hpp"

vector<string> Q;
stringstream S;
thread T;

bool test_A3_a() {
#ifdef A3_a
    running = true;
    Q.push_back("MATSE");
    start_thread();

    // Jetzt müssten 5 Buchstaben gesendet werden,
    // bei t1=0ms, t2=100ms, ... t5=400ms
    // Danach kämen dann '-', bei t6=500ms, t7=600ms
    // Das Ergebnis nach 650ms wäre also "MATSE--"
         
    this_thread::sleep_for(chrono::milliseconds(650));
    return (S.str() == "MATSE--");
#else
    return false;
#endif
}

bool test_A3_b() {
#ifdef A3_b
    S.str("");
    S.clear();
    
    // Warte auf ein '-'
    this_thread::sleep_for(chrono::milliseconds(110));

    // Sende 5 Buchstaben (500ms) und warte auf ein '-'
    send_word("halli");
    this_thread::sleep_for(chrono::milliseconds(600));

    // Sende 5 Buchstaben (500ms) und warte auf ein '-'
    send_word("hallo");
    this_thread::sleep_for(chrono::milliseconds(600));

    string s = S.str();
    return (s == "-halli-hallo-");
#else
    return false;
#endif
}

bool test_A3_c() {
#ifdef A3_c
    stop_thread();
    return (!T.joinable());   
#else
    return false;
#endif
}

int main() {
    StartTest("C++",3);
	AssertS("a) Thread gestartet  ",   test_A3_a() );
	AssertS("b) Wörter gesendet   ",   test_A3_b() );
	AssertS("c) Auf Thread warten ",   test_A3_c() );
    StopTest();
    return EXIT_SUCCESS;
}
