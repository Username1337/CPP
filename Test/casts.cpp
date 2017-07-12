#include <iostream>
#include <cmath>

using namespace std;

struct A {
	int value;
};

int main(){
	//IMPLIZIT CASTS
	bool   i1 = true;
	char   i2 = i1;
	int    i3 = i2;
	float  i4 = i3;
	double i5 = i4;
	cout << "Implizit:" << endl;
	cout << i1 << " " << i2 << " " <<i3 << " " <<i4 << " " <<i5<<endl;
	int i6 = 20489750;
	float i7 = i6;
	double i8 = i6;
	cout << "Implizit mit möglichen ungenauigkeiten" << endl;
	cout << i6 << " " << i7 << " " << i8 <<endl;

	//EXPLIZIT CASTS
	double e1 = 8374724.882739829347;
	float  e2 = (float)e1;
	int    e3 = (int)e2;
	char   e4 = (char)e3;
	bool   e5 = (bool)e4;
	cout << "Explizit:" << endl;
	cout << e1 << " " << e2 << " " <<e3 << " " <<e4 << " " <<e5<<endl;
	double e6 = 777.888;
	int e7 = (int)e6;
	int e8 = int(e6);
	int e9 = static_cast<int>(e6);
	cout << "Explizit 2:" << endl;
	cout << e6 << " " << e7 << " " << e8 << " " << e9 << endl;
	int e10 = (int) lround(e6);
	cout << "Explizit Runden" <<endl;
	cout << e10 <<endl;

	//STRING TO NUMBER
	string s = "88.99";
	int i = stoi(s);
	long int l = stol(s);
	double d = stod(s);
	float f = stof(s);
	cout << "String to numer" << endl;
	cout << i << " " << l << " " << d << " " << f << endl;

	//CONST CASTS
	const A* a = new A{5};
	const A& ar = *a;
	cout << a->value;
	cout << ar.value;
	A* b = const_cast<A*>(a);
	A& br = const_cast<A&>(ar);
	cout << b->value;
	cout << br.value;
	return 0;
}
