#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

	int n {};
	cout << "Wie viele Fibonacci Zahlen möchtest du haben" << endl;
	cin >> n;

	int erste = 1;
	int zweite = 2;
	for(int i=0; i<n; i++){
		int tmp = erste+zweite;
		erste = zweite;
		zweite = tmp;
		cout << zweite << endl;
	}
	
}
