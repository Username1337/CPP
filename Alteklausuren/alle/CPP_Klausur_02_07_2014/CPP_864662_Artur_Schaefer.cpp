// CPP SS2014, FH Aachen, Author: A.Voss@FH-Aachen.de

// TODO: Bitte Ausfuellen
const char * matse_name   = "Artur Schaefer";
const char * matse_matrnr = "864662";

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
#pragma GCC diagnostic ignored "-Wconversion"


// Konstanten (Intervallgrenzen) fuer die Aufgaben

const double a1 =  2.0, b1 =  4.0;
const double a2 = -3.0, b2 = -1.0;
const double a3 =  6.0, b3 =  8.0;



//-- A1 ------------------------------------

double f(double x) { return x+1; }

// TODO: A1.b) Signatur bzw. Datentyp fuer f auswaehlen und implementieren
template <typename T1>
double Quad(double a, double b, T1 f) {
    return (b-a)*f((b+a)/2);
}

// TODO: A1.a) Tangententrapezformel fuer obiges f(x)=x+1 implementieren
double Quad(double a, double b) {
	return (b-a)* (((a+b)/2) + 1);
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
    auto g = [](double x) { return x+1; };
	cout << "  Int_[a1,b1] g(x) dx = " << Quad(a1,b1,g) << endl;
	cout << "  Int_[a2,b2] g(x) dx = " << Quad(a2,b2,g) << endl;
	cout << "  Int_[a3,b3] g(x) dx = " << Quad(a3,b3,g) << endl << endl;
}


//-- A2 ------------------------------------

mutex m_sum;

// A2.a)
struct Intervall {
    double a;
    double b;
    
    // Konstruktor mit Übergabeparameter
    Intervall(double d1,double d2) : a(d1),b(d2){}
    
    // Freund zur Ausgabe
    friend ostream& operator<<(ostream& os, const Intervall& b)
    {
        os << "[" << b.a << ","<< b.b << "]"; 
        return os; 
    }
        
};


// A2.d) TODO: Template definieren analog zu Intervall
struct IntervallGeneric {

};

// A2.c) TODO: Naeherung berechnen
void Work(const Intervall & ivall, double & sum, mutex & myMutex) 
{       //Intervall & ivall,
        std::unique_lock<std::mutex> lk(myMutex);   // exception safe (RAII)
        sum+=Quad(ivall.a,ivall.b);
}

double Quad(const vector<Intervall>& IVs) {
    double sum = 0;
    mutex mutex_sum;
	// A2.c) TODO: threads anlegen und mit Worker Funktion und entsprechenden Parametern starten

    const int numthreads = IVs.size();
    thread *threads = new thread[numthreads];
   
    		
    for (int i=0; i<numthreads; ++i)
        threads[i] = thread(Work,ref(IVs.at(i)), ref(sum),ref(mutex_sum));
    
    for (int i=0; i<numthreads; ++i){
        (threads[i]).join();
        //delete (*threads[i]);
    }
    
    cout << "threads joined, sum=" << sum << endl << endl;

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
private:	
    vector<Intervall> v;
public:
	// A3.b) TODO: default-ctor
    AbgMenge() : v(){}

	// A3.c) TODO: ctor mit Intervall
    AbgMenge(Intervall intervall){
        v.push_back(intervall);
    }
    
     
	// A3.d) TODO: copy-ctor
	AbgMenge(const AbgMenge &abg): v(abg.v) {}

	// A3.e) TODO: ctor mit initializer_list
    AbgMenge(const initializer_list<Intervall>& l) 
    {
        for (Intervall x: l)
            add(x);   
    }

	// A3.f) TODO: Ausgabe-op
    friend ostream& operator<<(ostream& os, const AbgMenge& b)
    {
        if(b.v.empty()){
            os << "{ } size=0";
            return os;
        }
        os << "{ ";
        for (Intervall item: b.v)
        {
           os << item;
           if((b.v.back().a!=item.a) & (b.v.back().b!=item.b)){os << " ";}
        }
        os << " } size=" << b.v.size();
        return os; 
    }

	// A3.g) TODO: index-op
	Intervall &operator[](unsigned int n){
		if(n > v.size() - 1){
			throw 1;
		}
		return v[n];
	}

	// A3.h) TODO: Funktion add(intervall)
    void add(Intervall iv){
		if(v.size() == 0){
			v.push_back(iv);
		} else {
			vector<Intervall>::iterator itr = v.begin();
			while(itr != v.end() && (*itr).a < iv.a)
            { 
                ++itr; 
            }
			v.insert(itr, iv);
		}
	}

    // Aufgabe A3 i und j selber nochmal machen
	// A3.i) TODO: op+
	inline AbgMenge operator+(AbgMenge const &rhs) {
		return *this += rhs;
	}

	AbgMenge operator+=(const AbgMenge &am) {
		AbgMenge a;

		for(auto itr = v.begin(); itr < v.end(); ++itr){
			a.add(*itr);
		}

		for(auto itr = am.v.begin(); itr != am.v.end(); ++itr){
			a.add(*itr);
		}

		return a;
	}

	// A3.j) TODO: for-loop ermoeglichen
    // nested class definition inside
    class myiterator
    {
    private:
        const AbgMenge & d;    // we need to know which iterator we traverse
        size_t index;      // and the position

    public:
        myiterator(const AbgMenge & _d, size_t _index) : d(_d), index(_index) { }
        
        // for simplicity, compare identity and indices only
        bool operator!=(const myiterator& rhs) const
        {
            return (&d==&rhs.d) && (index!=rhs.index);
        }
        // hier gucken welcher Typ im Vector steckt
        Intervall operator*() const { return d.v[index]; }
     
        const myiterator& operator++()
        {
            ++index;
            return *this;   // standard return value
        }
    };
    
    myiterator begin () const { return myiterator(*this, 0); }
    myiterator end () const   { return myiterator(*this, v.size()); }
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
	cout << "  Ergebnis op+: M1={ ";
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

        //hier sortieren
   //     vector<Intervall> tmp;
   //     unsigned int size = v.size();
   //     for (unsigned int i=0; i<size; ++i)
   //     { 
   //         Intervall small(99999,0);
   //         for (unsigned int i=0; i<size; ++i)
    //        {   
      //          if(v.empty()){break;}
        //        small = v.at(0);
          //      if(v.at(i).a<small.a){small=v.at(i);}
            //    if( (v.back().a==v.at(i).a) ){       
              //      v.erase(v.at(i), v.at(i)+1);
                    //c.erase(c.begin()+2, c.begin()+5); 
                //}
            
            //Intervall small
        //} 
        //tmp.push_back(small);

        //}
        
        
            //!const_iterator
            //for (vector<Intervall>::iterator itor = v.begin(); itor!=v.end(); ++itor)
            //{
            //    if((*itor).a > iv.a){
            //        v.insert(itor,iv);
            //        break;
            //    }
            //}

	
