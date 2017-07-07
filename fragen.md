# Fragen

- delete normale objekte und ints und co
	- man kann nur sachen deleten aus dem heap
```
int* c = new int;
*c = 5;
delete c;
int* arr = new int[4];
delete [] arr;
```
- delete Array element
	- geht nicht
- delete vector element
	- erase remove kack, ist in der cpp gruppe
- G29 erase/remove reserve
	- was macht das?
	- ist in der cpp gruppe
- structs
- enums
	- grundlegend, wie funktionieren die?
	- enum { dim = 4 }
		- in einer klasse, warum kann man dim direkt als member verwenden über this->dim?
	- enum a { dim = 4 }
		- ohne klasse, kann man das auch ohne a machen?
- vererbung
	- was macht das public für nen unterschied?
	- friend ostream
- templates
	- hat T in B immer den gleichen type wie in A?
	```cpp
	template<typename T>
	class A {
		class B {
			T inhalt;
		}
	}
	```
	- wir kann ich in einem template sagen, dass es nicht alle typen nimmt, sondern nur welche die von einer klasse erben?
	```cpp
	template<typedef a extend Getraenke
	```
- globale variablen
	- wie funktionieren die
	- was ist so besonders an denen
- operatoren
	- können sie mir sagen, ob ich die consts überall richtig gesetzt habe?


# TODO
- condition variables
- casts
