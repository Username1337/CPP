/*	Author: A.Voss@FH-Aachen.de
 * 
 * Check I
 * 
 */

#include <iostream>
#include <iomanip>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-parameter"

// Bedeutung: n = a*m+b;
// A1.a)
 void myDiv(int n, int m, int& a, int& b) {
  a = n/m;
  b = n mod m;
 }

// A1.b)
 void myDiv(int n, int m, int* a, int* b) {
  myDiv(n,m, *a, *b);
 }

// A2
int myCount(const char* msg, char c) {
    int cnt = 0;
    
     for (const char* p= msg; (*p); ++p){
        if (*p == c) {
            cnt++;
        }
    }
    
    return cnt;
}

// A3
class Tuple {
    
    int a;
    int b;
    
    public:
    Tuple(int a, int b) : a(a), b(b) {}
    
    Tuple(const Tuple & t) : Tuple( t.a+1, t.b+2) {}   
     
     int get_a() {return a;}
     int get_b() {return b;}
     
     ~Tuple(){}
    
};

int main()
{
    cout << "Check I" << endl << endl;

    // A1
    int n = 42, m = 5;
    int a = 0, b = 0;
    
    // A1.a)
    // Aufruf myDiv;
    cout << "A1.a) Erg: " << n << "=" << a << "*" << m << "+" << b << endl;

    // A1.b)
    // Aufruf myDiv;
    cout << "A1.b) Erg: " << n << "=" << a << "*" << m << "+" << b << endl << endl;

    // A2
    const char* msg = "A2.a) Text mit vielen 'e's";
    cout << "A2.a) Anzahl 'e's in \"" << msg << "\": " << myCount(msg,'e') << endl << endl;
    
    // A3
     Tuple t1(1,2);   // a=1, b=2
     Tuple t2(t1);    // a=2, b=4
     cout << "A3.a) t1.a=" << t1.get_a() << ", t1.b=" << t1.get_b() << endl; 
     cout << "      t2.a=" << t2.get_a() << ", t2.b=" << t2.get_b() << endl; 
    
    return EXIT_SUCCESS;
}

