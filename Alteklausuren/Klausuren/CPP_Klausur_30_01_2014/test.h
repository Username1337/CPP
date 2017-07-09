#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ident.h"

void StartTest(const char * module, unsigned int ANo)
{
    if (!strcmp(matse_name,   "Vorname Nachname") ||
        !strcmp(matse_matrnr, "123456")) {
        printf("*** Sie müssen in der Datei ident.h noch ihre Daten eintragen ***\n");
        exit(1);
    }

    printf("\n--- Klausur %s, Wintersemester 2013/14, Aufgabe %d\n",module,ANo);
    printf("\n    Name:   %s\n    MatrNr: %s\n",matse_name, matse_matrnr);
    printf("\n--- Testfälle\n\n");
}

void AssertS(const char * info, int result) 
{ 
    printf("    Test %-14s: %s\n",info,((result)?"OK":"FAILED")); 
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
