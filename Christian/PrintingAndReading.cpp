#include <stdio.h>

using namespace std;

// C Style
printf("/* text to be printed out */");
printf("Character %c\n", 'A');
printf("Double %f\n", 2.2424);
printf("Integer %d\n", 792);
printf("String %s\n", "Hello World");
printf("Size_t %zu\n", sizeof(int));

#include <iostream>

// C++ Style
cout << "/* text to be printed out */" << endl;
cout << "Character " << 'A' << endl;
cout << "Double " << 2.2424 << endl;
cout << "Integer " << 792 << endl;

#include <iostream>

int i;
cin >> i; // gets the value for i via the console
