#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int x = 5;
	int* p = &x;
	std::cout << x << " - " << &x << std::endl;
	std::cout << p << " - " << &p << " : " << *p << std::endl;
	x = x+5;
	std::cout << x << " - " << &x << std::endl;
	std::cout << p << " - " << &p << " : " << *p << std::endl;
	x = *p+5;
	std::cout << x << " - " << &x << std::endl;
	std::cout << p << " - " << &p << " : " << *p << std::endl;
	*p = *p+5;
	std::cout << x << " - " << &x << std::endl;
	std::cout << p << " - " << &p << " : " << *p << std::endl;
}
