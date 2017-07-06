# Wichtige Notizen

## Wichtige Elemente
- [CPP References](reference/en/cpp.html)

- Hello World
	```cpp
	#include <iostream>
	#include <string>

	using namespace std;

	int main(){
		cout << "Hello World" << endl;
		return 0;
	}
	```

- Ein/Ausgabe
	```cpp
	int i;
	cin >> i;
	cout << i;
	```

- andere coole sachen
	```cpp
	int x{}, y{};			//initialisiert x und y mit 0
	```

## Datentypen

- Primitive Datentypen
	- `size_t`
		- positiver int

- Casts
	- TODO

- Arrays
	- beim übergeben an Funktionen die Länge mit geben!
	- wichtige befehle
		```cpp
		size_t length = 3;				//size
		int arr[length];				//stack
		int* arr = new int[length];		//heap
		//sonstiges
		cout << arr[2];					//get
		arr[2] = 5;						//set
		//TODO geht nicht
		arr[2] = nullptr;				//remove
		//iterate
		for(int x: arr){ ... }
		for(size_t i=0; i<sizeof(arr)/sizeof(int); ++i){ ... }
		```

- CPP Arrays
	- [CPP References](reference/en/cpp/container/array.html)

- Vector
	- `#include <vector>`
	- Arraylist
	- how to use
		```cpp
		vector<int> v();			//stack
		vector<int> v{1,2,3};		//stack
		vector<int>* v = new vector<int>();			//heap
		vector<int>* v = new vector<int>{1,2,3};	//heap
		//sonstiges
		v.push_back(3);				//append
		v[3];						//get
		v[3] = 2;					//set
		//TODO remove
		v.erase(remove(...)) ??? (G29)
		v.size();					//size
		//iterate
		for(auto x: v){...}
		//count vector elements if lambda expression returns true
		int cnt1 = count_if (v.begin(), v.end(), [](int k){ return (0==k%2);});
		auto result1 = find_if(v.begin(), v.end(), [](int k){ return (0==k%2);});
		```
	- [CPP References](reference/en/cpp/container/vector.html)

- Set
	- `#include <set>`
	- Menge
		- es gibt keine doppelten Elemente
	- How to use:
		```cpp
		set<int> s = {1,2,3};
		s.insert(3);
		s.size();
		```
	- [CPP References](reference/en/cpp/container/set.html)

- Unordered Map
	- `#include <unordered_map>`
	- AssoziativesArray/HashMap
	- How to use
		```cpp
		unordered_map<long,long> map;
		```
	- [CPP References](reference/en/cpp/container/unordered_map.html)

- Chrono
	- `#include <chrono>`
	- Für die Zeitmessung
	- `G_classes/G26_timing.cpp`
	- how to use
		```cpp
		void f(){
			this_thread::sleep_for(chrono::milliseconds(2134));		//sleep 2134 ms
			this_thread::sleep_for(chrono::seconds(2));				//sleep    2 s
		}
		auto t1 = chrono::high_resolution_clock::now();
		f();
		auto t2 = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << "ms";
		```
	- [CPP References](reference/en/cpp/chrono.html)

- Math
	- `#include <cmath>`

## Datenstrukturen

- Structs
	- Klassen ohne Funktionen mit nur public members
	```cpp
	//TODO
	```

- Enums
	//TODO
	- Liste mit Konstanten
	- wird zur Compilezeit festgelegt
	- How to use
	```cpp
	enum { dim = 4 };
	```

- Unions
	//TODO

## Funktions Pointer

- Type Definition
	```cpp
	typedef double(*func_t)(double);
	//func_t ist jetzt der Name für Funktionen dieses Aufbaus
	```

- wichtige Befehle
	```cpp
	vector<func_t> v;						//vector der diese Funktionen enthält
	double quad(double x){ return x*x }		//neue func_t Funktion
	v.push_back(quad);						//Funktion zu vector hinzufügen
	v.push_back(&quad);						//das selbe
	v[0](4);								//ausführen, liefert 16
	```

## Konstruktoren

- `Constructor mit: a(a)`
	```cpp
	Bruch(int zaehler, int nenner): zaehler(zaehler), nenner(nenner){}
	```

- `Copy Constructor`
	```cpp
	Bruch(const Bruch& alt): zaehler(alt.zaehler), nenner(alt.nenner){}
	```

- `Destructor`
	```cpp
	~Bruch(){}
	```

- `{} Constructor`
	- Stack
		```cpp
		Queue q = {3,4,5}
		```
	- Heap
		```cpp
		Queue* q = new Queue{3,4,5}
		```
	- Constructor:
		```cpp
		Queue(const initializer_list<int>& liste){
			for(int x: liste){
				this->elemente.push_back(x);
			}
		}
		```

## Operatoren
- [Stackoverflow](reference/operatoren.html)

- `Operatoren: == !=`
	```cpp
	bool operator==(const Queue& rechts){
		return this->elemente == rechts.elemente;
	}
	bool operator!=(const Queue& rechts){
		return !(*this==rechts);
	}
	```

- `Operatoren: *= += /= -=`
	```cpp
	Queue& opertator+=(const Queue& rechts){
		for(int i: rechts.elemente){
			this->elemente.push_back(i);
		}
		return *this;
	}
	```

- `Operatoren: * + / -`
	- links ist eine copy und das return auch

	```cpp
	friend Queue operator+(Queue links, const Queue& rechts){
		links+=rechts;
		return links;
	}
	//oneliner
	friend Queue operator+(Queue links, const Queue& rechts){ return links+=rechts; }
	```

- `Operator: <<`
	```cpp
	friend ostream& operator<<(ostream& os, const Bruch& b){
		os << b.zaehler << "/" << b.nenner;
	}
	```

- `Operator: >>`
	```cpp
	friend istream& operator>> (istream& istr, complex& a){}
	```

- `Operator: []`
	- you should always provide both methods

	```cpp
	//setter
	value_type& operator[](index_type idx){		//index_type is for example size_t
		return this->elemente[idx];
	}
	//getter
	const value_type& operator[](index_type idx) const{
		return this->elemente[idx];
	}
	```

- `Operator: ++a`
	- zuerst den Wert erhöhen, dann returnen

	```cpp
	Bruch& operator++(){
		++zaehler; ++nenner;
		return *this;
	}
	```

- `Operator: a++`
	- zuerst returnen, dann den Wert erhöhen

	```cpp
	Bruch operator++(int){
		Bruch tmp(*this);
		++zaehler; ++nenner;
		return tmp;
	}
	```

- `Operatoren später überladen`
	```cpp
	class Bruch {
		public:
			friend const Bruch& operator+(const Bruch& links, const Bruch& rechts);
	};

	const Bruch& Bruch::operator+(const Bruch& links, const Bruch& rechts){
		...
	}
	```

## Iterator
- man kann mit `for(auto a: A)` über die Elemente iterieren
- Beispiel in lectures/Grinnah.cpp
- G23\_ranged\_base\_for.cpp:
	```cpp
	class D {
		// nested class definition inside
		class myiterator
		{
			private:
				const D & d;			// we need to know which iterator we traverse
				size_t index;			// and the position
			public:
				myiterator(const D & _d, size_t _index) : d(_d), index(_index) { }
				// for simplicity, compare identity and indices only
				bool operator!=(const myiterator& rhs) const{
					//die beiden listen müssen gleich sein, aber die position anders
					return (&d==&rhs.d) && (index!=rhs.index);
				}
				double operator*() const {
					return d.v[index];
				}
				const myiterator& operator++(){
					++index;
					return *this;		// standard return value
				}
		};
		private:
			vector<double> v;
		public:
			// use initializer_list from vector
			D(const initializer_list<double>& l) : v(l) { }
			myiterator begin () const { return myiterator(*this, 0); }
			myiterator end () const   { return myiterator(*this, v.size()); }
	};
	```

## Statics
```cpp
class C {
	private:
		static int cnt;			//direkte initialisierung mit "=0" ist nicht erlaubt
	public:
		C() { ++cnt; }
		static int get_cnt(){ return cnt; }
};
int C::cnt = 0;					//es muss außerhalb initialisiert werden
```

## Consts
- rückwärts lesen!
- das erste kann auf beiden seiten stehen
- const vars
	```cpp
	//lets you change all
	int*											//pointer to int
	//lets you change what it points to, but not the value
	int const *										//pointer to constant int
	//lets you change the value, but not what it points to
	int * const										//constant pointer to int
	//lets you change nothing
	int const * const								//constant pointer to constant int
	//das erste kann auf beiden seiten stehen
	const int * == int const *
	const int * const == int const * const
	```

- const functions
	//TODO check if this is richtig
	- normal
		```cpp
		const int getX() {}
		int const getX() {}
		int getX() const {}			//this wird nicht geändert
		```

	- referenz
		```cpp
		const Queue & getQueue() {}
		Queue const & getQueue() {}
		Queue & const getQueue() {}
		und macht eine int referenz eigentlich sinn?
		const int & getQueue() {}
		int const & getQueue() {}
		int & const getQueue() {}
		```
	
	- pointer
		```cpp
		const Queue * getQueue() {}
		Queue const * getQueue() {}
		Queue * const getQueue() {}
		const int * getQueue() {}
		int const * getQueue() {}
		int * const getQueue() {}
		```

## Vererbung
- Einfache Vererbung
	- beim erstellen
		1. Zuerst wird die Basis-Klasse erstellt
		2. Dann die Kind-Klasse
	- beim löschen
		1. Zuerst wird die Kind-Klasse zerstört
		2. Dann die Basis-Klasse
	- `A* l = new B(4);`
		- A ist der dynamische Type, da er sich ändern kann
		- B ist der statische Type, da er sich nicht ändern kann
	- `virtual` muss in Basis-Klasse stehen

	```cpp
	class A {
		protected:
			int n;
		public:
			A(int N) : n(N) {}
			void f(){}						//nimm immer die methode des dynamischen Types
			virtual void g(){}				//nimm immer die methode des statischen Types
			virtual void h(){}				//nimm immer die methode des statischen Types
			virtual void i() final {}		//final methode kann nicht überschieben werden
	};
	class B: public A {						//B erbt von A
		public:
			B(int N): A(N) {}
			void f(){}						//verdeckt die methode
			//virtual void f(){}			//für alle kinder ist es virtual, aber nicht wenn man als dynamischen Type A hat
			virtual void g(){}				//überschreibt die methode
			void h(){}						//überschreibt die methode und ist immernoch virtual
			//virtual void i() final {}		//geht nicht, da es final ist
	};
	class C final: public A { ... };		//man kann nicht mehr von C Erben
	A a;
	B b;
	//normal
	a.f();				//gibt A::f() aus
	a.g();				//gibt A::g() aus
	b.f();				//gibt B::f() aus
	b.g();				//gibt B::g() aus
	//Dynamischer Type ist A
	A* ap = new A();
	A* bp = new B();
	ap->f();			//gibt A::f() aus
	ap->g();			//gibt A::g() aus
	bp->f();			//gibt A::f() aus, weil es in A nicht virtual ist
	bp->g();			//gibt B::g() aus
	//Als Referenz verhält es sich genauso wie als pointer
	A& ar = a;
	A& br = b;
	ar.f();				//gibt A::f() aus
	ar.g();				//gibt A::g() aus
	br.f();				//gibt A::f() aus, weil es in A nicht virtual ist
	br.g();				//gibt B::g() aus
	//ohne void in der vererbten
	ap->h();			//gibt A::h() aus
	bp->h();			//gibt B::h() aus, obwohl in B nicht virtual steht
	```

- Abstrakte Klassen (abstract class) / Interfaces
	- eine Klasse, von der man keine Objekte erstellen kann
	- Interfaces gibt es nicht

	```cpp
	class IReport {
		virtual void CreateReport() = 0;		//"=0" means pure virtual
	};
	class Report: IReport {
		//muss die pure virtual methods erstellen, sonst ist es auch eine abstracte klasse
		virtual void CreateReport(){ ... }
	};
	```

- Mehrfach Vererbung
	- Ausgefranzt
		- Es gibt 2 mal A

		```cpp
		class A {
			protected:
				int n;
			public:
				A(int N): n(N) {}
		};
		class B1: public A {
			public:
				B1(int N): A(N) {}
		};
		class B2: public A {
			public:
				B2(int N): A(N) {}
		};
		class C: public B1, public B2 {
			public:
				C(int N): B1(N+1), B2(N+2) {}
				int getB1N(){
					return B1::n;
				}
				int getB2N(){
					return B2::n;
				}
		};
		B1 b1;		//zuerst wird A erstellt, dann B1
		B2 b2;		//zuerst wird A erstellt, dann B2
		C c;		//zuerst A, B1, dann A, B2, dann C
		//beim Löschen:
		//C: zuerst C, dann B2, A, dann B1, A
		```

	- Geschlossen
		- Es gibt 1 mal A

		```cpp
		class A {
			protected:
				int n;
			public:
				A(int N): n(N) {}
		};
		class B1: public A {
			public:
				B1(int N): A(N) {}
		};
		class B2: public A {
			public:
				B2(int N): A(N) {}
		};
		class C: public B1, public B2 {
			public:
				C(int N): A(N), B1(N+1), B2(N+2) {}			//A muss vor den anderen erstellt werden
				int getN(){
					return n;
				}
		};
		B1 b1(1);		//zuerst wird A erstellt, dann B1 (n ist 1)
		B2 b2(1);		//zuerst wird A erstellt, dann B2 (n ist 1)
		C c(1);			//zuerst A, B1, B2, dann C (n ist 3)
		//beim Löschen:
		//C: zuerst C, dann B2, B1, A
		```

## Templates

- Template Klassen
	```cpp
	template <typename T>
	class Point {
		public:
			typedef T value_type;			//type of the value
			typedef T key_type;				//type of the key
			typedef T size_type;			//type of the size
			//setzt value_type auf T, damit man von außerhalb den Type erfahren kann
			T x;
			T y;
	};
	```

- Spezialisierung
	```cpp
	template <typename T, int N>
	class Point { ... };
	template <typename T>
	class Point<T, 3> { ... };
	template <int N>
	class Point<double, N> { ... };
	```

- Einzelne Funktionen Spezialisieren
	```cpp
	template<typename T>
	class Bruch {
		T getGGT(){ ... }
	}
	template<>
	int Bruch<int>::getGGT(){ ... }
	```

- Template Funktionen
	```cpp
	template <typename T1, typename T2>
	void Rotate(T1& t1, T2& t2){
		T1 tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	```

- Template mit Werten, anstelle von Typen
	```cpp
	template <typename T, int N>
	class MyVector {
		enum { dim = N };
		T data[dim];
		//einen vorgegebenen type nutzen und einen anderen
		template <typename S>
		MyVector& operator=(const MyVector<S,N>& v){ ... }
	};
	//Vector der Dimension 3
	MyVector<int, 3> mv;
	```

## Lambdas
- normal
	```cpp
	auto add = [](int n) { return n+4; };
	auto inc = [](int& n) { return ++n; };
	add(4);		//returns 8
	int x=7;
	inc(x);		//increases x
	```
- copy outer vars
	```cpp
	int m = 12;
	auto addToM = [=](int n) { return m+n; };
	addToM(4);	//returnt die summe aus m und 4
	```
- reference outer vars
	- vars können geändert werden

	```cpp
	auto setM = [&](int n) { m=n };
	setM(5);	//setzt m auf 5
	```
- andere syntaxe
	```cpp
	auto pi = []() -> double { return 3.1415926; };
	typedef double (*polynome_t)(double x);
	polynome_t quad = [](double x) { return x*x; };
	//count vector elements if lambda expression returns true
	int cnt1 = count_if (v.begin(), v.end(), [](int k){ return (0==k%2);});
	auto result1 = find_if(v.begin(), v.end(), [](int k){ return (0==k%2);});
	```

## Smart Pointer
- Unique Pointer
	- `#include <memory>`

	```cpp
	C* c = new C(4)
	unique_ptr<C> p1(c);
	unique_ptr<C> p2;
	p2 = move(p1)				//verschiebt das objekt von p1 nach p2
	p1.get()					//gibt den zeiger zu dem objekt zurück
	*p1							//gibt das objekt selber zurück
	```

- Shared Pointer
	- `#include <memory>`

	```cpp
	C* c = new C(4)
	shared_ptr<C> s1(c);
	shared_ptr<C> s2(c);
	s.reset()					//löscht s
	p1.get()					//gibt den zeiger zu dem objekt zurück
	*p1							//gibt das objekt selber zurück
	```

## Threads
- wenn man ein programm startet, wird der main thread gestartet
- bei mehreren kernen laufen die threads parallel ab
- beim kompilieren `-pthread` anhängen
- thread führt funktion aus
- how to
	```cpp
	void Work(int sec){
		this_thread::sleep_for(chrono::seconds(sec));
	}
	thread t1(Work, 1);
	thread t2(Work, 2);
	thread t3([](){ this_thread::sleep_for(chrono::seconds(2)); }); //mit lambda
	t2.join();				//wait for t2
	t1.join();				//wait for t1
	```

- threads mit referenzen aufrufen
	```cpp
	void Work(int& sec){
		this_thread::sleep_for(chrono::seconds(sec));
	}
	thread t1(Work, ref(4));
	```

- mutex / kritische regionen
	- `#include <condition_variable>`
	- sperrt threads vor dem zugriff auf variablen, oder ganze bereiche eines codes
	- [CPP References](reference/en/cpp/thread/mutex.html)

	- unsichere methode
		```cpp
		void Work(int* sum, mutex* mutex_sum){
			for (int i=0; i<n; ++i){
				mutex_sum->lock();
				(*sum) += 1;
				mutex_sum->unlock();
			}
		}
		mutex mutex_sum;				//erstelle einen mutex
		int x = 0;
		thread t1(Work, &x, &mutex_sum)
		```

	- sichere methode
		```cpp
		void Work(int* sum, mutex* mutex_sum){
			for (int i=0; i<n; ++i){
				loack_guard<mutex> lk(*mutex_sum);
				(*sum) += 1;
			}
		}
		mutex mutex_sum;				//erstelle einen mutex
		int x = 0;
		thread t1(Work, &x, &mutex_sum)
		```

	- wait until unlock
		- `mutex.try_lock()`
			- returnt false, wenn es gelocked ist
			- wenn es nicht gelocked ist, wird es gelocked und true returnt

		```cpp
		//zählt solange hoch, bis signal geunlocked wird
		//und lockt es direkt wieder, geht aber aus der schleife raus
		while (!signal.try_lock()){
			++cnt;
		}
		//jetzt wieder unlocken
		signal.unlock();
		```

- condition variablen
	- wartet auf ein ereignis
	- TODO
