# Wichtige Notizen

## Wichtige Elemente

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

## Datentypen

- Primitive Datentypen
	- `size_t`
		- positiver int

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
		v.size();					//size
		//iterate
		for(auto x: v){...}
		```

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

- Unordered Map
	- `#include <unordered_map>`
	- AssoziativesArray/HashMap
	- How to use
		```cpp
		unordered_map<long,long> map;
		```

- Chrono
	- `#include <chrono>`
	- Für die Zeitmessung
	this_thread::sleep_for(chrono::seconds(2));

- Limits
	- `#include <limits>`
	- How to use
		```cpp
		```

- Math
	- `#include <cmath>`
	- How to use
		```cpp
		```

## Datenstrukturen

- Structs
	- Klassen ohne Funktionen mit nur public members
	```cpp
	//TODO
	```

- Enums
	- Liste mit Konstanten
	- wird zur Compilezeit festgelegt
	- How to use
	```cpp
	enum { dim = 4 };
	```

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

## Operatoren / Konstruktoren

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
	```cpp
	friend const Queue& operator+(const Queue& links, const Queue& rechts){
		Queue* neu = new Queue(links);
		neu+=rechts;
		return *neu;
	}
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
	```cpp
	int& operator[](size_t idx){ 
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
				const D & d;    // we need to know which iterator we traverse
				size_t index;      // and the position
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
					return *this;   // standard return value
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

## Templates

- Template Klassen
	```cpp
	template <typename T>
	class Point {
		public:
			typedef T value_type;
			//setzt value_type auf T, damit man von außerhalb den Type erfahren kann
			T x;
			T y;
	};
	```

- Spezialisierung
	```cpp
	template <typename T int N>
	class Point { ... };
	template <typename T>
	class Point<T, 3> { ... };
	template <int N>
	class Point<double, N> { ... };
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
- beim kompilieren -pthread anhängen
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

- kritische regionen
	- `#include <condition_variable>`
	```cpp
	mutex_sum->lock();
	(*sum) += inc;
	mutex_sum->unlock();
	```
	- wenn dazwischen ein error geworfen wird, dann wird es nicht geunlocked (exception safe)
		```cpp
		lock_guard<mutex> lk(*mutex_sum);
		(*sum) += inc;
		```
