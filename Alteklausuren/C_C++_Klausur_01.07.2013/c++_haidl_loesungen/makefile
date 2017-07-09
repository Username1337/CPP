# Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

all: c_A1.out c_A2.out c_A3.out cpp_A3.out cpp_A1.out cpp_A2.out

%.out: %.c %.h
	gcc -ansi -pedantic -Wall -Wextra -Wconversion -std=c99 $< -o $@

%.out: %.cpp %.hpp
	g++ -ansi -pedantic -Wall -Wextra -Wconversion -std=c++11 -g -pthread $< -o $@


