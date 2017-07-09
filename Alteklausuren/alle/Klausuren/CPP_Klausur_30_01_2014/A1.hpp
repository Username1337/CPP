#include <iostream>
#include <string>
using namespace std;

/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
//#define A1_a
//#define A1_b
//#define A1_c
//#define A1_d
//#define A1_e

class Audioformat {
public:

    string titel() { return ""; }
    string info()  { return ""; }
};

int mp3_counter = 0;

class MP3_Format : public Audioformat {
public:
    
    string titel() { return  song; }
    string info()  { return "MP3"; }

private:
    string song;
};
