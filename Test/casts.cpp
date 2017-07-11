#include <iostream>

using namespace std;

struct A {
	int value;
};

int main(){
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
