# Author: A.Voss@FH-Aachen.de

CC	= g++
CFLAGS	= -std=c++11 
LDFLAGS = -lm 
#-z muldefs

# default targets
all: J1_link_example_V1.out J2_link_example_V2.out

J1_link_example_V1.out: J1_link_example_main_V1.o J1_link_example_extern_V1.o
	$(CC) J1_link_example_main_V1.o J1_link_example_extern_V1.o $(LDFLAGS) -o $@

J1_link_example_main_V1.o: J1_link_example_main_V1.cpp
	$(CC) -c $(CFLAGS) $< -o $@

J1_link_example_extern_V1.o: J1_link_example_extern_V1.cpp
	$(CC) -c $(CFLAGS) $< -o $@


J2_link_example_V2.out: J2_link_example_main_V2.o 
	$(CC) J2_link_example_main_V2.o $(LDFLAGS) -o $@

J2_link_example_main_V2.o: J2_link_example_main_V2.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm *.out *.o


#	g++ -ansi -pedantic -Wall -Wextra -Wconversion -std=c++11 -pthread $< -lm -o $@

#cpp_files   = $(shell find . -name '*.cpp' -print -type f)
# out_files = $(cpp_files:.cpp=.out)
#out_files = A_extern_example_I.out

#all: $(out_files)

#%.out: %.cpp
#	g++ -ansi -pedantic -Wall -Wextra -Wconversion -std=c++11 -pthread $< -lm -o $@
