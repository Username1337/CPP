#include "test.h"
#include "A2.hpp"

//////////////// a) ////////////////

bool test_A2_a() {
#ifdef A2_a
	einlesen();
	return ( text.size() == 8          &&
			 text[0] == "euphorisiert" &&
			 text[1] == "eines"        &&
			 text[2] == "Geschmack"    &&
			 text[3] == "gekuehlten"   &&
			 text[4] == "Der"          &&
			 text[5] == "Lebensmittelkontrolleure" &&
			 text[6] == "Magermilchjogurts" &&
			 text[7] == "uebereifrige" );

#else
	return false;
#endif
}

//////////////// b) ////////////////

bool test_A2_b()  {
#ifdef A2_b
	return (  lambda1('a') &&  lambda1('A') &&
	          lambda1('e') &&  lambda1('E') &&
		  lambda1('i') &&  lambda1('I') &&
		  lambda1('o') &&  lambda1('O') &&
		  lambda1('u') &&  lambda1('U') &&
		 !lambda1('b') && !lambda1('B') &&
		 !lambda1('h') && !lambda1('H') );
#else
	return false;
#endif
}

//////////////// c) ////////////////

bool test_A2_c() {
#ifdef A2_c
	return ( 5  == lambda2("Magermilchjogurt") &&
			 5  == lambda2("MAGERMILCHJOGURT") &&
			 10 == vokal_counter);
	#else
	return false;
#endif
}

//////////////// d) ////////////////

bool test_A2_d() {
#ifdef A2_d
	auto f = getComp();
	return (  f("aei", "AEiO") &&
		 !f("IUo", "uiA")  &&
		 !f("OuAE","eUo"));
#else
	return false;
#endif
}

//////////////// e) ////////////////

bool test_A2_e() {
#ifdef A2_e
	sortieren();
	return ( text.size() == 8          &&
			 text[0] == "Der"          &&
			 text[1] == "Geschmack"    &&
			 text[2] == "eines"        &&
			 text[3] == "gekuehlten"   &&
			 text[4] == "Magermilchjogurts" &&
			 text[5] == "euphorisiert" &&
			 text[6] == "uebereifrige" &&
			 text[7] == "Lebensmittelkontrolleure" );

#else
	return false;
#endif
}

///////////////// main ////////////////

int main() {
	StartTest("C++",2);
	AssertS("a) Einlesen",  test_A2_a() );
	AssertS("b) Lambda 1",  test_A2_b() );
	AssertS("c) Lambda 2",  test_A2_c() );
	AssertS("d) getComp",   test_A2_d() );
	AssertS("e) Sortieren", test_A2_e() );
    StopTest();
    return EXIT_SUCCESS;
}
