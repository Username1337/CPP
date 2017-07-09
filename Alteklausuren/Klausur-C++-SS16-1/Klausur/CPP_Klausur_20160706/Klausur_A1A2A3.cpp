/* C++ Klausur 6.7.2016, FH Aachen
 * 
 * Name:
 * Matr.Nr.:
 * 
 */

#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <vector>
#include <thread>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"

// A1
//----

// a) generische Klasse Txy 
class Txy {
// b) member x,y
// c) ctor
};
// d) Typ xy_t

// e) Klasse xyListe, erbt von vector<xy_t>
class xyListe {
// f) privater ctor

// g) Fabrikmethode wandle, Parameter der Form (3,3, { {1,0},{0,1} }), siehe L1
// h) Fabrikmethode wandle, Parameter der Form ("blinker"), siehe L2
// i) Fabrikmethode wandle, Parameter der Form (vector<int>({3,3,0,0,0,1}), siehe L3

// j) Ausgabeoperator<<
};


// A2
//----

class FeldBasis {
public:
// a) ctor fuer vector<xy_t>, member size_x, size_y
// b) int-Zeiger feld fuer dynamisch allokiertes int-Feld
// c) feld initialisiert entsprechend vector

// d) Operator() zum Lesen (const) und zum Schreiben
//    Parameter int k, int x, int y
 
// e) Ausgabeoperator<<

// f) dtor


// A3
//----

// a) rein virtuelle Methode void schritt()

// b) Member no

// c) von x0..x1 (ohne x1), y0..y1 (ohne y1)
    void teilschritt(int x0, int x1, int y0, int y1) { }
};

// d) Klasse FeldSeriell erbt von FeldBasis
class FeldSeriell {
// implementiert schritt()
};

// e) Klasse FeldParallel erbt von FeldBasis
class FeldParallel {
//    implementiert schritt() parallel mit 4 Threads
// f) Worker/Threadfunktion mit lambda-Ausdruck
};


int main()
{
    /* Muster, senkrechter und waagerechter Blinker
     * 8 5
       0 0 0 0 0 0 0 0
       0 1 0 0 0 0 0 0
       0 1 0 0 1 1 1 0
       0 1 0 0 0 0 0 0
       0 0 0 0 0 0 0 0
     */
    xyListe L1{}; // = xyListe::wandle(8,5,{ {1,1},{1,2},{4,2},{5,2},{6,2},{1,3} }); 
    xyListe L2{}; // = xyListe::wandle("blinker.txt");
    xyListe L3{}; // = xyListe::wandle(vector<int>{8,5,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

    cout << endl << "Listen:" << endl;
    // cout << "  L1:" << L1 << endl;
    // cout << "  L2:" << L2 << endl;
    // cout << "  L3:" << L3 << endl;
    
    // mit dieser Liste das Spiel starten (l1,L2 oder L3)
    xyListe& L = L1;
    
    cout << endl << "Seriell:" << endl;
    // FeldSeriell FS(L);
    // cout << FS << endl;
    // FS.schritt();
    // cout << FS << endl;

    cout << endl << "Parallel:" << endl;
    // FeldSeriell FP(L);
    // cout << FP << endl;
    // FP.schritt();
    // cout << FP << endl;

    return EXIT_SUCCESS;
}

