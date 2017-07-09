# C++ Prüfung, WS 2013/14, Terstegge/Voss

# CXX = clang++
CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -std=c++11 -g -pthread

SRCS = A1.cpp A2.cpp  A3.cpp  A4.cpp
BINS = $(SRCS:.cpp=.out)

all:	$(BINS)

%.out:%.cpp
	$(CXX) $(CXXFLAGS) -o $@  $<

clean:
	rm -f $(BINS) *~ 
	
# DO NOT DELETE
A1.out:   A1.hpp A1.cpp test.h ident.h
A2.out:   A2.hpp A2.cpp test.h ident.h
A3.out:   A3.hpp A3.cpp test.h ident.h
A4.out:   A4.hpp A4.cpp test.h ident.h

