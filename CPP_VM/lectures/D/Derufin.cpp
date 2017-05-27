#include <iostream>
#include <cstdlib>
using namespace std;

int pot(int b, int n){
	int out = 1;
	for(int i = 0; i<n; i++){
		out *= b;
	}
	return out;
}

int main() {
	// berechnet b^n
	int b {};
	int n {};

	cout << "Geben Sie b ein: " << endl;
	cin >> b;

	cout << "Geben Sie n ein: " << endl;
	cin >> n;

	int out = pot(b,n);
	cout << out;
}
