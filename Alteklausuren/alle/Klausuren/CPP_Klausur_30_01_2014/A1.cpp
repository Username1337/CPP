#include "test.h"
#include "A1.hpp"
#include <iostream>
#include <functional>

//////////////// a) //////////////////

bool test_A1_a() {
#ifdef A1_a
	Audioformat * af = new MP3_Format("Hey Joe");
	string info = af->info();
	string absp = af->titel();
	return (info == "MP3" && absp == "Hey Joe");
#else
	return false;
#endif
}

//////////////// b) //////////////////

bool test_A1_b()  {
#ifdef A1_b
	MP3_Format mp3("South of the border");
	const MP3_Format c_mp3("Lolipopp");
	string s1 = mp3;
	string s2 = c_mp3;
	return (s1 == "South of the border" && s2 == "Lolipopp");
#else
	return false;
#endif
}

///////////////// c) /////////////////

bool test_A1_c() {
#ifdef A1_c
	mp3_counter = 0;

	MP3_Format mp1;
	MP3_Format mp2("Hey Joe");
	MP3_Format * mp3 = new MP3_Format("Lollipop");
	MP3_Format mp4(mp1);
	MP3_Format mp5(mp1);
	delete mp3;

	return (4 == mp3_counter);
#else
	return false;
#endif
}

//////////////// d) //////////////////

bool test_A1_d() {
#ifdef A1_d
        MP3_Format mp1("SongA");
        MP3_Format mp2("SongB");
        MP3_Format mp3("SongA");
        
	return ((mp1 == mp3) && (mp1 != mp2));
#else
	return false;
#endif
}

///////////////// e) //////////////////

bool test_A1_e() {
#ifdef A1_e

	MP3_Format mp3a = "Summertime";
	MP3_Format mp3b;
	mp3b = "Summertime";
	
	string ta = mp3a.titel();
	string tb = mp3b.titel();

	return (ta == "Summertime" &&
		tb == "Summertime" );
#else
	return false;
#endif
}

/////////////// main ////////////////

int main() {
    StartTest("C++",1);
    AssertS("a) ", test_A1_a() );
    AssertS("b) ", test_A1_b() );
    AssertS("c) ", test_A1_c() );
    AssertS("d) ", test_A1_d() );
    AssertS("e) ", test_A1_e() );
    StopTest();
    return EXIT_SUCCESS;
}

