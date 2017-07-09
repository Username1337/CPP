#include <iostream>

using namespace std;

struct A {
	double n;
	bool m;
};

struct B {
	int n;
	int m=3;
};

struct C {
	A a1;
	A a2;
};

int strucs(){
	A a {3.14159, true};
	cout << a.n << " " << a.m << endl;
	B b;
	b.n=5;
	cout << b.n << " " << b.m << endl;
	C c{ {1, true}, {4.5, false} };
	cout << c.a1.n << " " << c.a1.m << endl;
	cout << c.a2.n << " " << c.a2.m << endl;
	A* ap = new A{2,true};
	cout << (*ap).n <<endl;
	return 1;
}

enum D{a=3,b=3,c=3};
enum E {d,e,f};

int enums(){
	cout << D::a;
	cout <<E::d;
	cout << b;
	/* E e; */
	/* e.a=3; */
	/* cout << e.a; */
	return 1;
}

class Test {
	int x;
	public:
	const int& getX(){
		return x;
	}
	void setX(const int& x){
		this->x=x;
	}
};

int main(){
	/* strucs(); */
	enums();
	cout <<endl;
	Test t;
	int x = 4;
	t.setX(x);
	cout <<x<<endl;
	cout <<t.getX()<<endl;
	t.setX(2);
	/* t.getX()=3; */
	cout <<x<<endl;
	cout <<t.getX()<<endl;
	return 1;
}
