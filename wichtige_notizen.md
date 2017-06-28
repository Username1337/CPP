# Wichtige Notizen

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

- Besondere datentypen
	- `size_t`
		- positiver int

- Arrays
	- beim übergeben an Funktionen die Länge mit geben!
	- stack
		```cpp
		size_t length = 3;
		int arr[length];
		```
	- heap
		```cpp
		size_t length = 3;
		int arr* = new arr[length];
		```
	- get/set/foreach/for
		```cpp
		cout << arr[2]; //get
		arr[2] = 5; //set
		arr[2] = nullptr; //remove
		for(int x: arr){ ... }
		for(size_t i=0; i<sizeof(arr)/sizeof(int); ++i){ ... }
		```

- Vector
	- `#include <vector>`
	- Stack
		```cpp
		vector<int> v();
		vector<int> v{1,2,3};
		```
	- Heap
		```cpp
		vector<int>* v = new vector<int>();
		vector<int>* v = new vector<int>{1,2,3};
		```
	- wichtige Befehle:
		```cpp
		//ein element anhängen
		v.push_back(3);
		//get element
		v[3];
		//iterate
		for(auto x: v){...}
		```

## Datenstrukturen
- Klassen
	```cpp
	//TODO
	```

- Structs
	- Klassen ohne Funktionen mit nur public members
	```cpp
	//TODO
	```

- Enums
	- Liste mit Konstanten
	```cpp
	//TODO
	```

## Funktions Pointer
- Type Definition
	```cpp
	typedef double(*func_t)(double);
	//func_t ist jetzt der Name für Funktionen dieses Aufbaus
	```
- wichtige Befehle
	```cpp
	vector<func_t> v; //vector der diese Funktionen enthält
	double quad(double x){ return x*x } //neue func_t Funktion
	v.push_back(quad); //Funktion zu vector hinzufügen
	v.push_back(&quad); //das selbe
	v[0](4); //ausführen, liefert 16
	```

## Templates
