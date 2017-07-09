/* C++ Klausur 6.7.2016, FH Aachen
 *
 * Name:        Hans Mueller
 * Matr.Nr.:    123456
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
template<typename T1, typename T2>
class Txy {
public:
// b) member x,y
    T1 x;
    T2 y;

// c) ctor
    Txy(T1 t1, T2 t2) : x(t1), y(t2) {}
};

// d) Typ xy_t
typedef Txy<int, int> xy_t;

// e) Klasse xyListe, erbt von vector<xy_t>
class xyListe : public vector<xy_t> {
// f) privater ctor
    xyListe() {}

public:
// g) Fabrikmethode wandle, Parameter der Form (3,3, { {1,0},{0,1} }), siehe L1
    static xyListe& wandle(int w, int h, const initializer_list<xy_t>& initl) {
        xyListe* l = new xyListe();

        l->push_back(xy_t(w, h));
        for (xy_t p : initl) {
            l->push_back(xy_t(p.x, p.y));
        }

        return *l;
    }

// h) Fabrikmethode wandle, Parameter der Form ("blinker"), siehe L2
    static xyListe* wandle(string file_path) {
        FILE* file = fopen(file_path.c_str(),"r");
        int words = -1;

        if (file != NULL) {
            char *line = (char*)malloc(1024);
            size_t n = 20;
            ssize_t len;
            int lines = 0;

            while ((len = getline(&line, &n, file)) > 0) {
                if (lines == 0) {
                    // TODO
                } else {
                    // TODO
                }

                lines++;
            }

            free(line);
            fclose(file);
        }

        return new xyListe();
    }

// i) Fabrikmethode wandle, Parameter der Form (vector<int>({3,3,0,0,0,1}), siehe L3
    static xyListe& wandle(vector<int> coords) {
        xyListe* l = new xyListe();

        for (unsigned int i = 0; i < coords.size(); i += 2) {
            l->push_back(xy_t(coords[i], coords[i+1]));
        }

        return *l;
    }

// j) Ausgabeoperator<<
    friend ostream& operator<<(ostream& os, const xyListe& l ) {
        os << "[";

        for (unsigned int i = 0; i < l.size(); i++) {
            xy_t item = l[i];
            os << " (" << item.x << "," << item.y << ")";
        }

        os << " ]";
        return os;
    }
};


// A2
//----

class FeldBasis {
    int* feld;

protected:
    int size_x;
    int size_y;

public:
// a) ctor fuer vector<xy_t>, member size_x, size_y
    FeldBasis(vector<xy_t>& v) : size_x(v[0].x), size_y(v[0].y), no(0) {
        // b) int-Zeiger feld fuer dynamisch allokiertes int-Feld
        this->feld = new int[2 * size_x * size_y];
        for (int i = 0; i < 2 * size_x * size_y; i++) {
            feld[i] = 0;
        }

        // c) feld initialisiert entsprechend vector
        for (unsigned int i = 1; i < v.size(); i++) {
            xy_t cell = v[i];
            (*this)(1, cell.x, cell.y, 1);
        }
    }


// d) Operator() zum Lesen (const) und zum Schreiben
//    Parameter int k, int x, int y
    int operator()(int k, int x, int y) {
        int offset = k * this->size_x * this->size_y;
        unsigned int index = offset + (x % this->size_x) + this->size_y * (y % this->size_y);

        int value = this->feld[index];
        return value;
    }

    // TODO sollte wahrscheinlich anders geloest sein
    void operator()(int k, int x, int y, int new_val) {
        int offset = this->no * this->size_x * this->size_y;
        unsigned int index = offset + (x % this->size_x) + this->size_x * (y % this->size_y);

        this->feld[index] = new_val;
    }


// e) Ausgabeoperator<<
    friend ostream& operator<<(ostream& os, const FeldBasis& f ) {
        os << f.size_x << " " << f.size_y << endl;

        int offset = f.no * f.size_x * f.size_y;

        for (int y = 0; y < f.size_y; y++) {
            for (int x = 0; x < f.size_x; x++) {
                unsigned int index = offset + (x % f.size_x) + f.size_y * (y % f.size_y);

                // TODO besser mit () operator
                os << f.feld[index] << " ";
            }
            os << endl;
        }

        return os;
    }

// f) dtor
    ~FeldBasis() {
        delete [] feld;
    }

// A3
//----

// a) rein virtuelle Methode void schritt()
    virtual void schritt() = 0;

// b) Member no
    int no;

// c) von x0..x1 (ohne x1), y0..y1 (ohne y1)
    void teilschritt(int x0, int x1, int y0, int y1) {
        int no_new = 1 - this->no;

        for (int x = x0; x < x1; x++) {
            for (int y = y0; y < y1; y++) {
                // nachbarn zaehlen
                int n = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }

                        n += (*this)(this->no, x, y);
                    }
                }
                //cout << "n=" << n << endl;

                int current_state = (*this)(this->no, x, y);

                if (current_state == 0 && n == 3) {
                    // set 1
                    (*this)(no_new, x, y, 1);
                } else if (current_state == 1 && n != 2 && n != 3) {
                    // set 0
                    (*this)(no_new, x, y, 0);
                } else {
                    // set current_state
                    (*this)(no_new, x, y, current_state);
                }
            }
        }
    }
};

// d) Klasse FeldSeriell erbt von FeldBasis
class FeldSeriell : public FeldBasis {
public:
    FeldSeriell(vector<xy_t>& v) : FeldBasis(v) {}

    // implementiert schritt()
    void schritt() {
        this->teilschritt(0, this->size_x, 0, this->size_y);
        this->no = 1-this->no;
    }
};

// e) Klasse FeldParallel erbt von FeldBasis
class FeldParallel : public FeldBasis {
public:
    FeldParallel(vector<xy_t>& v) : FeldBasis(v) {}

    // implementiert schritt()
    void schritt() {
        //    implementiert schritt() parallel mit 4 Threads

        // f) Worker/Threadfunktion mit lambda-Ausdruck
        const int numthreads = 4;
        thread threads[numthreads];

        threads[0] = thread([&]() { teilschritt(0, this->size_x/2, 0, this->size_y/2); });
        threads[1] = thread([&]() { teilschritt(this->size_x/2, this->size_x, 0, this->size_y); });
        threads[2] = thread([&]() { teilschritt(0, this->size_x, this->size_y/2, this->size_y); });
        threads[3] = thread([&]() { teilschritt(this->size_x/2, this->size_x, this->size_y/2, this->size_y); });

        // wait for completition
        for (auto& t : threads) {
            t.join();
        }

        this->no = 1-this->no;
    }
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
    xyListe L1 = xyListe::wandle(8,5,{ {1,1},{1,2},{4,2},{5,2},{6,2},{1,3} });
    //xyListe L2 = xyListe::wandle("blinker.txt");
    xyListe L3 = xyListe::wandle(vector<int>{8,5,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

    cout << endl << "Listen:" << endl;
    cout << "  L1:" << L1 << endl;
    //cout << "  L2:" << L2 << endl;
    cout << "  L3:" << L3 << endl;

    // mit dieser Liste das Spiel starten (l1,L2 oder L3)
    xyListe& L = L1;

    cout << endl << "Seriell:" << endl;
    FeldSeriell FS(L);
    cout << FS << endl;
    FS.schritt();
    cout << FS << endl;

    cout << endl << "Parallel:" << endl;
    FeldParallel FP(L);
    cout << FP << endl;
    FP.schritt();
    cout << FP << endl;

    return EXIT_SUCCESS;
}
