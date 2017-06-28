# Wichtige Notizen

## Operatoren / Constructoren
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
		Queue(initializer_list<int> liste){
			for(int x: liste){
				this->elemente.push_back(x);
			}
		}
		```

- `Operatoren: *= += /= -=`
	```cpp
	const Queue& opertator+=(const Queue& rechts){
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

- `Operator: []`
	```cpp
	const int operator[](size_t idx){ 
		return this->elemente[idx];
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
- Besondere datentypen
	- `size_t`
		- positiver int

- Arrays
	- keine ahnung, aber brauchen wir die überhaupt?

- Vector
	- `#include <vector>`
	- Stack
		- `vector<int> v();`
		- `vector<int> v{1,2,3};`
	- Heap
		- `vector<int>* v = new vector<int>();`
		- `vector<int>* v = new vector<int>{1,2,3};`
	- wichtige Befehle:
		```cpp
		//ein element anhängen
		v.push_back(3);
		//get element
		v[3];
		//iterate
		for(auto x: v){...}
		```

