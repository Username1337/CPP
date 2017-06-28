#include <iostream>
#include <vector>

using namespace std;

typedef double (*funktion)(double x);

double eval(funktion f, double x){
	return f(x);
}

int main(){
	auto add = [](int n1, int n2, int n3){
		return n1+n2+n3;
	};
	cout << add(1,2,3)<<endl;
	int a = 0;
	int b = 5;
	auto test = [=](int n){
		if(n>=a && n<=b){
			return true;
		} else {
			return false;
		}
	};
	cout << test(3)<< endl;
	cout << test(9)<< endl;
	int z = 20;
	auto reverse = [&](){
		z=-z;
	};
	reverse();
	cout << z <<endl;

	funktion quad = [](double n){ return n*n; };
	cout << eval(quad, 4);

	return 1;
}
