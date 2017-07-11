#include <cmath>

// implicit casting chain
bool -> char -> int -> float -> double

// explicit casting chain
double -> float -> int -> char -> bool

// explicit casting methods
int i;
double d = 2.239;

// cuts of the part of the number which cannot be displayed in int
i = (int) d;
i = int(d);
i = static_cast<int>(d);

// rounds the double
i = (int) lround(d);

// from string to number type
string s;
int i = stoi(s);
long int l = stol(s);
double d = stod(s);
float f = stof(s);
