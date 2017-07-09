// CPP SS2014, FH Aachen, Author: A.Voss@FH-Aachen.de

// TODO: Bitte Ausfuellen
const char * matse_name   = "Cedric Hanebaum";
const char * matse_matrnr = "4005854";

// Achtung:
//----------
// Es gibt am Ende ein main(), welches die Funktionen Aufgaben1..3 aufruft.
// Je nach Fortschritt die Aufgabenteile ein- bzw. auskommentieren!
//
// Es gibt Punkte fuer Ideen, auch wenn sie aus einem technischen Grund nicht
// compilieren. Genauso gibt es Abzuege, falls das Programm nicht compiliert
// oder aber die Loesung signifikant ineffizient oder umstaendlich ist.



// includes
#include <iostream>
#include <cstdlib>
#include <thread>
#include <condition_variable>
#include <vector>
#include <functional>
#include <initializer_list>
#include <cmath>
#include <mutex>
using namespace std;

// disable Warning
#pragma GCC diagnostic ignored "-Wunused-parameter"


// Konstanten (Intervallgrenzen) fuer die Aufgaben

const double a1 =  2.0, b1 =  4.0;
const double a2 = -3.0, b2 = -1.0;
const double a3 =  6.0, b3 =  8.0;



//-- A1 ------------------------------------

double f(double x) { return x+1; }

// TODO: A1.b) Signatur bzw. Datentyp fuer f auswaehlen und implementieren
template<typename Func>
double Quad(double a, double b, Func f) {
	return (b - a) * f ((a + b) / 2);
}

// TODO: A1.a) Tangententrapezformel fuer obiges f(x)=x+1 implementieren
double Quad(double a, double b) {
	return (b - a) * (((a + b) / 2) + 1);
}

void Aufgabe1()
{
	cout << endl << "-- A1 ------------------------------------" << endl << endl;

	// A1.a)
	cout << "  Int_[a1,b1] f(x) dx = " << Quad(a1,b1) << endl;
	cout << "  Int_[a2,b2] f(x) dx = " << Quad(a2,b2) << endl;
	cout << "  Int_[a3,b3] f(x) dx = " << Quad(a3,b3) << endl << endl;

	// A1.b) TODO: Nachfolgende Ausdruecke einkommentieren, wenn Quad definiert ist.
	cout << "  Int_[a1,b1] f(x) dx = " << Quad(a1,b1,f) << endl;
	cout << "  Int_[a2,b2] f(x) dx = " << Quad(a2,b2,f) << endl;
	cout << "  Int_[a3,b3] f(x) dx = " << Quad(a3,b3,f) << endl << endl;

	// A1.c) TODO: Nachfolgende Ausdruecke einkommentieren, wenn g und Quad definiert sind.
	auto g = [](double x) -> double {return x + 1;};
	cout << "  Int_[a1,b1] g(x) dx = " << Quad(a1,b1,g) << endl;
	cout << "  Int_[a2,b2] g(x) dx = " << Quad(a2,b2,g) << endl;
	cout << "  Int_[a3,b3] g(x) dx = " << Quad(a3,b3,g) << endl << endl;
}


//-- A2 ------------------------------------

mutex m_sum;

struct Intervall {
	double a, b;
	Intervall(double _a, double _b): a(_a), b(_b){}

	friend ostream& operator<<(ostream &os, Intervall const &i ) {
		return os << "[" << i.a << "," << i.b << "]";
	}

};

// A2.d) TODO: Template definieren analog zu Intervall
template<typename T>
struct IntervallGeneric {
	T a, b;
	IntervallGeneric(T _a, T _b):a(_a), b(_b){}
};

// A2.c) TODO: Naeherung berechnen
void Work(const Intervall &v, double &sum){
	m_sum.lock();
	sum += Quad(v.a, v.b);
	m_sum.unlock();
}

double Quad(const vector<Intervall>& IVs) {
	double sum = 0.0;
	thread* threads[IVs.size()];


	// A2.c) TODO: threads anlegen und mit Worker Funktion und entsprechenden Parametern starten
	for(long unsigned int i = 0; i < IVs.size(); ++i){
		// threads[i] = thread(Work, IVs[i], sum);
		// Funktioniert nicht, warum auch immer...
	}

	for(long unsigned int i = 0; i < IVs.size(); ++i){
		// (*(threads[i])).join();
		// Funktioniert nicht, siehe oben
		// delete threads[i];
	}

	return sum;
}

void Aufgabe2()
{
	cout << endl << "-- A2 ------------------------------------" << endl << endl;

	// A2.b) TODO: wenn der ctor mit zwei Argumenten vorhanden ist, nachfolgende Zeile
	//             und Aufruf einkomentieren.
	vector<Intervall> IVs = { Intervall(a1,b1), Intervall(a2,b2), Intervall(a3,b3) };

	cout << "  Sum_i Int_[a_i,b_i] f(x) dx = " << Quad(IVs) << endl << endl;
}


//-- A3 ------------------------------------

class AbgMenge {
	// A3.a) TODO: member vector<Intervall>
	vector<Intervall> ivs;

public:
	// A3.b) TODO: default-ctor
	AbgMenge(){}

	// A3.c) TODO: ctor mit Intervall
	AbgMenge(Intervall iv){
		ivs.push_back(iv);
	}

	// A3.d) TODO: copy-ctor
	AbgMenge(const AbgMenge &abg){
		for(auto itr = abg.ivs.begin(); itr != abg.ivs.end(); ++itr){
			Intervall i((*itr).a, (*itr).b);
			ivs.push_back(i);
		}
	}

	// A3.e) TODO: ctor mit initializer_list
	AbgMenge(const initializer_list<Intervall>& l): ivs(l){}

	// A3.f) TODO: Ausgabe-op
	friend ostream & operator<<(ostream & os, AbgMenge const &abg ) {
			os << "{ ";

			for(long unsigned int i = 0; i < abg.ivs.size(); ++i){
				os << abg.ivs[i];
			}

			return os << " } size = " << abg.ivs.size();
	}

	// A3.g) TODO: index-op
	Intervall &operator[](long unsigned int n){
		if(n > ivs.size() - 1){
			throw 1;
		}
		return ivs[n];
	}

	// A3.h) TODO: Funktion add(intervall)
	void add(Intervall iv){
		if(ivs.size() == 0){
			ivs.push_back(iv);
		} else {
			auto itr = ivs.begin();
			while(itr != ivs.end() && (*itr).a < iv.a){ ++itr; }
			ivs.insert(itr, iv);
		}
	}

	// A3.i) TODO: op+
	inline AbgMenge operator+(AbgMenge const &rhs) {
		return *this += rhs;
	}

	AbgMenge operator+=(const AbgMenge &rhs) {
		AbgMenge a;

		for(auto itr = ivs.begin(); itr < ivs.end(); ++itr){
			a.add(*itr);
		}

		for(auto itr = rhs.ivs.begin(); itr != rhs.ivs.end(); ++itr){
			a.add(*itr);
		}

		return a;
	}

	// A3.j) TODO: for-loop ermoeglichen
	class myiterator{
	private:
		const AbgMenge &abg;
		long unsigned int index;

	public:
		myiterator(const AbgMenge &_abg, long unsigned int _index) : abg(_abg), index(_index) { }

		bool operator!=(const myiterator& rhs) const{
				return (&abg==&rhs.abg) && (index!=rhs.index);
		}

		Intervall operator* () const { return abg.ivs[index]; }

		const myiterator & operator++(){
				++index;
				return *this;
		}
	};

	myiterator begin () const { return myiterator(*this, 0); }
	myiterator end () const   { return myiterator(*this, ivs.size()); }

};

void Aufgabe3()
{
	cout << endl << "-- A3 ------------------------------------" << endl << endl;

	// A3.f) TODO: Ausgabe Intervall
	Intervall I1(a1,b1), I2(a2,b2), I3(6,8);
	cout << "  I1=" << I1 << ", I2=" << I2 << ", I3=" << I3 << endl << endl;

	// A3.b)..e) TODO: ctor
	// A3.f) TODO: Ausgabe AbgMenge
	AbgMenge M1;
	cout << "  M1=" << M1 << endl;
	AbgMenge M2(I1);
	cout << "  M2=" << M2 << endl;
	AbgMenge M3{I3,I2};
	cout << "  M3=" << M3 << endl << endl;

	try {
		// A3.g) TODO: index-op und exception
		cout << "  M3[1]=" << M3[1] << endl;
		cout << "  M3[2]=" << M3[2] << endl << endl;
	} catch (...) {
		cout << "  Indexfehler" << endl << endl;
	}

	// A3.i) TODO: operation einkommentieren
	M1 = M2 + M3;
	cout << "  Ergebnis op+: M1={";
	// A3.j) TODO: loop einkommentieren
	for (auto I:M1) cout << I << " ";
	cout << "}" << endl << endl;

}

int main()
{
	cout << endl << "-- Klausur C++, SS2014_1" << endl;
    cout << "  Name: " << matse_name << ", MatrNr: " << matse_matrnr << endl << endl;

	Aufgabe1();
	Aufgabe2();
	Aufgabe3();

    return EXIT_SUCCESS;
}
