#include <iostream>

using namespace std;

template<int b, int n>
class Potenz {
	public:
		enum { v = Potenz<b, n-1>::v * b };
};

template<int b>
class Potenz<b, 1> {
	public:
		enum { v = b };
};

template<int b>
class Potenz<b, 0> {
	public:
		enum { v = 1 };
};

int main(){
	cout << Potenz<1,200>::v;
	return 0;
}
