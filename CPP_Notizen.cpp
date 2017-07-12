/* Author: Jan Gruenenwald
 * 
 * Notizen fuer die CPP-Klausur
 * 
 * Wenn kompiliert wird, muss für Thread-Methoden -pthread angehängt werden!
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cmath>
#include <condition_variable>
#include <unordered_map>

using namespace std;

// Methoden auf:
// 		Sets - set<int> s = {1, 2, ...}; s.insert(1);
// 		Vectors - vector<int> v = {1, 2, ...}; v.push_back(1);

// Thread safe Programmierung
void Work1(mutex& m, string restArgs[]) {
	// do something;
	while(!m.try_lock()) {
		// do something;
	}
	m.unlock();
	
	/* In Main:
	 * 
	 * mutex s;
	 * s.lock();
	 * threads anlegen und work aufrufen mit ref(s); ES GIBT AUCH CREF FUER CONST REFS
	 * s.unlock();
	 * threads joinen;
	 */
}

// lock_guard<mutex> ist Exceptionsafe!
void Work2(mutex* m, string restArgs[]) {
	lock_guard<mutex> lk(*m);
	// Alternativ unique_lock<mutex> lk(*m); lk.lock(); ... lk.unlock();
	// ODER 
	// lock_guard<recursive_mutex> lk(*m); lk.lock(); ... lk.unlock();
}

// Template Programmierung
template <typename T>
class Test {
public:
	T x;
	static T n;
	// Darf nicht direkt initialisiert werden, Initialisierung muss außerhalb mit Test::n = ... erfolgen
	
	Test() {
		
	}
	
	Test(T x) : x(x) { }
	// ...
		
	// Templates auch in Funktionen erlaubt
	template<typename S>
	Test& operator=(const Test<S>& W) {
		x = (T) W.x;
		return *this;
	}
};

template <typename T1, typename T2>
struct ReturnType;

template <>
struct ReturnType<int, double> {
	typedef double value_type;
};
template <typename T>
struct ReturnType<T, T> {
	typedef T value_type;
};

// Berechnung zur Kompilierzeit
template<int b, int n>
class Potenz {
	enum { v = b * Potenz<b - 1, n>::v };
};
template<int b>
class Potenz<b, 0> {
	enum { v = 1 };
};
// Benennung von Template Spezialisierungen
template<int b>
using hochNull = Potenz<b, 0>; 

template<typename T>
class TypeInfo {
public:
	static size_t CalcSize() { return sizeof(T); }
};

// Shared & Unique Pointer
void doSomething() {
	unique_ptr<Test<int>> p1(new Test<int>()); // unique_ptr will als Argument einen Pointer
	unique_ptr<Test<int>> p2;
	p2 = move(p1);
	
	vector<unique_ptr<Test<int>>> v;
	v.push_back(unique_ptr<Test<int>>(new Test<int>()));
	unique_ptr<Test<int>> p = move(v[0]);
	
	shared_ptr<Test<int>> p1a(new Test<int>());
	// BESSER:
	auto p1b = make_shared<Test<int>>(Test<int>());
}

// Rvalues & Lvalues
class SomethingSomething {
	int m = 5; // globale Variable, hat Adresse, LValue
	
	string get_name() { return "Test"; } // Reiner Rückgabewert, RValue
	
	void f(const string& s) {
		// LValue Variante
	}
	void f(const string&& s) {
		// RValue Variante
	}
	
	SomethingSomething(const SomethingSomething&&) {
		// Constructor für RValues
	}
	
	SomethingSomething& operator=(const SomethingSomething&&) {
		// = Operator für RValues
	}
};

// Lambda Expressions
void lambdaExpressions() {
	auto res = 5; // Belegung mit beliebigem Rückgabewert
	// Struktur Lambda:= []()->{}; ODER [](){}; ODER []()->double{};
	auto add1 = [](int& n){return ++n;}; 
	// [=] alle Variablen werden kopiert, [&] alle werden referenziert, [a, &b] a kopiert, b referenziert
	auto trapezrule = [=](function<double(double)>f)->double{return 0.5*((f(1)+f(2))*(2-1));};
	auto A = trapezrule([](double x)->double{return x*x;}); // Integration eines Lambdas in ein anderes Lambda
	function<double(double)> func = [](double x){return x*x*x;}; // Deklaration einer Funktion
	// Defintion von allem wo ein double hereingereicht und ein double zurückgegeben wird als polynom_t
	typedef double (*polynom_t)(double x);
}

// Implementation eines Sets + initializer_list
template<typename T>
class set {
private:
	unsigned int max_elements;
	vector<T> data;
public:
	set(unsigned int max_elements, const initializer_list<T>& l) : max_elements(max_elements), data(l) { data.reserve(max_elements); }
	bool contains(T n) { for (auto x : data) if (x == n) return true; return false; }
	void remove_value(T n) { data.erase(remove(data.begin(), data.end(), n), data.end()); }
};

// Iteratoren schreiben
class A {
private:
	vector<double> v;
	
public:
	myIterator begin() const { return myIterator(*this, 0); }
	myIterator end() const { return myIterator(*this, v.size()); }
	
	class myIterator {
	private:
		const A& a;
		size_t idx;
	public:
		myIterator(const A& a, size_t idx) : a(a), idx(idx) { }
		bool operator!=(const myIterator& rhs) const { return (&a == &rhs.a) && (idx != rhs.idx); }
		double operator*() const { return a.v[idx]; }
		const myIterator& operator++() { ++ idx; return *this; }
	};
};

// Initialisierungsmethoden
class B {
	int n = 5; int m {42}; int y,z{};
	int a[3] = {1, 2, 3}; int b[2]{1, 2}; int* c = new int[2]{1, 2};
};


int main() {
	// do_Something();
}
