/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Das bekannteste C++-Programm.
 * 
 *  Stichworte:
 *      - #include, iostream, cstdlib
 *      - std::cout, std::endl, C-String "text"
 *      - using namespace
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Hello Welt !!" << endl; 
	for(int i=0; i<10; i++){
		cout << i*6 << endl;
	}
	return EXIT_SUCCESS;
}

