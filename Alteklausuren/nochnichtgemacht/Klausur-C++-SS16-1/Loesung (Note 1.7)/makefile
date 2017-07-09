# Author: A.Voss@FH-Aachen.de
# ---
# simple makefile compiling all *.c and *.cpp source files into *.out executables
# using gcc or g++ resp. clang or clang++ compiler!

# compiler settings
CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -O3
CXX = g++
# CXX = clang++
CXXFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion
LDFLAGS = -lm

# collect all c and c++ files
CEXAMPLES = $(shell find . -name '*.c' -print -type f)
CXXEXAMPLES = $(shell find . -name '*.cpp' -print -type f)

CTARGETS = $(CEXAMPLES:.c=.out)
CXXTARGETS = $(CXXEXAMPLES:.cpp=.out) 

# build them all
all: $(CTARGETS) $(CXXTARGETS)

%.out: %.c
	$(CC) $(CFLAGS) -std=c99 $< $(LDFLAGS) -o $@

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -pthread -std=c++11 $< $(LDFLAGS) -o $@

#--- gcc work-around (thread problem)
#	g++ -ansi -pedantic -Wall -Wextra -Wconversion -std=c++11  -pthread -Wl,--no-as-needed $< -lm -o $@

# clean *.out files
.PHONY: clean
clean:
	rm *.out

