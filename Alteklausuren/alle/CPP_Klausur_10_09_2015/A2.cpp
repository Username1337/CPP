#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <list>

using namespace std;


//Aufgabenteil a)
double Quad(double a, double b) {
    double len = b - a;
    double fun_arg = (a + b)/2;
    double fun_val = fun_arg + 1;
    
    double result = len*fun_val;
    return result;
}

//testet Aufgabe a)
void aufgabe_a_test() {
    //in den Folgenden Tests sollte das Ergebnis nicht nur eine Naeherung, sondern korrekt sein, da die
    //Trapezregel lineare Funktionen perfekt annaehert.
    
    //auf [0,1] steigt die Funktion linear von 1 bis 2, der erwartete Funktionswert ist also 1,5
    cout  << "Quad(0, 1) = " << Quad(0, 1) << "; 1,5 erwartet" << endl;
    
    //auf [1,2] steigt die Funktion linear von 2 bis 3, der erwartete Funktionswert ist also 2,5
    cout  << "Quad(1, 2) = " << Quad(1, 2) << "; 2,5 erwartet" << endl;
    
    //Summe muesste also 4 sein
    cout  << "Quad(0, 2) = " << Quad(0, 2) << "; 4 erwartet" << endl;
}

//Aufgabenteil b)
typedef double (*math_fun)(double);

//Anmerkung: Signatur ist durch den typedef einfacher zu lesen
//folgendes wäre auch möglich
//double Quad(double a, double b, double (*f)(double)) {
double Quad(double a, double b, math_fun f) {
    double len = b - a;
    double fun_arg = (a + b)/2;
    double fun_val = f(fun_arg);
    
    double result = len*fun_val;
    return result;
}

//testet Aufgabe b)

double mal2(double x) {
    return x*2;
}

void aufgabe_b_test() {
    //auf [0,1] steigt die Funktion linear von 0 bis 2, der erwartete Funktionswert ist also 1
    cout  << "Quad(0, 1, mal2) = " << Quad(0, 1, mal2) << "; 1 erwartet" << endl;
    
    //auf [1,2] steigt die Funktion linear von 2 bis 4, der erwartete Funktionswert ist also 3
    cout  << "Quad(1, 2, mal2) = " << Quad(1, 2, mal2) << "; 3 erwartet" << endl;
    
    //Summe muesste also 4 sein
    cout  << "Quad(0, 2, mal2) = " << Quad(0, 2, mal2) << "; 4 erwartet" << endl;
}

//Aufgabe c)
void aufgabe_c() {

    //Deklaration von g:
    //Bemerkung: man könnte g hier auch wieder ohne typedef deklarieren, oder sogar als Auto
    
    math_fun g = [](double x) {return x+1;}; //mit unserem typedef
    //auto g = [](double x) {return x+1;}; //mit auto
    //double (*g)(double) = [](double x) {return x+1;}; //direkt als Funktionszeiger

    //auf [0,1] steigt die Funktion linear von 1 bis 2, der erwartete Funktionswert ist also 1,5
    cout  << "Quad(0, 1, g) = " << Quad(0, 1, g) << "; 1,5 erwartet" << endl;
    
    //auf [1,2] steigt die Funktion linear von 2 bis 3, der erwartete Funktionswert ist also 2,5
    cout  << "Quad(1, 2, g) = " << Quad(1, 2, g) << "; 2,5 erwartet" << endl;
    
    //Summe muesste also 4 sein
    cout  << "Quad(0, 2, g) = " << Quad(0, 2, g) << "; 4 erwartet" << endl;
}

int main()
{
    cout << "Test Aufgabe a)" << endl;
    aufgabe_a_test();
    cout << endl << endl;
    
    cout << "Test Aufgabe b)" << endl;
    aufgabe_b_test();
    cout << endl << endl;
    
    cout << "Test Aufgabe c)" << endl;
    aufgabe_c();
    cout << endl;
}
