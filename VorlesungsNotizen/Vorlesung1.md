
## Literatur
- Der c++ Programmierer Breymann
- c++ kurz und gut Loudon

## Prüfung
- 2h Zeit
- elektronisch
- abgabe im ilias

## cpp
- #include <iostream>
- using namespace std;
- cout //console out
- cout << "blabla" << endl; //print blabla and new line
- cout << "bla" << i*2 << endl;
- g++ example.cpp -o example.out
- int i = 23;
- int i; //keine compiler fehler
	- liegt auf dem stack
	- zufällige zahl aus dem speicher
	- variablen initialisieren
- int main() { ... }
- void k() { ... }
- cout << i*2/0 << endl;
	- warning division by zero
	- compiliert trotzdem
	- es wird ein fehler geschmissen und das programm stürzt ab

## c
- #include <stdio.h>
- int main(){ ... }
- printf("...");
- printf("i=%d \n",i);
	- printf ist eine fehler quelle
	- möglich mismatch zwischen parameter und type im string
- gcc example.c -o example.o

## make
- guckt welche datei ist von welcher abhängig
- compiliert dateien deren abhängigkeiten jünger sind

## cpp
- return EXIT_SUCCESS; //makro, return erfolgreich

## Primitive Datentypen
- int
	- ganze zahlen
- unsigned int
	- ganze zahl, 0 oder positiv
- signed int
	- int
- const int
	- int der nicht mehr verändert werden kann
- sizeof(intvar)
	- returns 4byte
- int32_t /int8_t /int16_t
- uint32_t
	- 32 bit großer int
	- int hat unterschiedliche größe je nach prozessor
- size_t
	- größe von datentypen
- bool
- char
- unsigned char
- signed char
	- char = 53 //ascii e´zeichen 53
- short
- long
- long long
- float
- double
- long double

## klassen
- #include <iomanip>
- #include <string>
- string s = "bal";
- printf("%s",s.c_str())
- in c
	- const char\* pc = "bla";
- char ca[] = "bla";

## input
- int n;
- cout << "eingabe n: ";
- cin >> n;

## kontrollstrukturen
- if (n==2){ ... }
- if (n=2){ ... } //geht
- if (!n)
- if ((n=3\*4+5) > 0)
- for (i=min,sum=0; i<=max; i++){ ... }
- geht, ist aber schlecht:
	- ++i<=max
	- sum+=i
	- label:
		- goto label;
- continue
- break
- while (i<=5){ ... }
- do { ...  }while();
