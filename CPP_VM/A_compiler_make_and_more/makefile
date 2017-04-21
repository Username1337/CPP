# Author: A.Voss@FH-Aachen.de
#
# Ein einfaches makefile.
# Statt g++ ist auch clang++ moeglich.
#
# Ausfuehren im Terminal-Fenster (LXTerminal)
# > make
#

all: example1.out example2.out

example1.out : example1.o
	gcc example1.o -o example1.out

example1.o : example1.c
	gcc -c example1.c
	
example2.out : example2.cpp
	g++ example2.cpp -o example2.out

clean:
	rm *.o *.out
	
