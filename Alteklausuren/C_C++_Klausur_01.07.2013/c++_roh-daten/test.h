// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"

const char * matse_name();
const char * matse_matrnr();

void StartTest(const char * module, unsigned int ANo)
{
    printf("\n--- Einführung in %s, Prüfung Sommer 2013, Aufgabe %d\n",module,ANo);
    printf("\n    Name:   %s\n    MatrNr: %s\n",matse_name(),matse_matrnr());
    printf("\n--- Testfälle\n\n");
}

void Assert1(size_t no, int result) 
{ 
    printf("    Test %d: %s\n",no,((result)?"OK":"FAILED")); 
}

void Assert2(size_t no, size_t subno, int result) 
{ 
    printf("    Test %d%c: %s\n",no,(char)('a'+subno),((result)?"OK":"FAILED")); 
}

void StopTest()
{
    printf("\n--- Fertig\n\n");
}
