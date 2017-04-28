#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

	int n {};
	cout << "Bis zu welcher Zahl soll gerechnet werden?" << endl;
	cin >> n;

	for(int i = 2; i<n; i++){
		bool teilbar = false;
		for(int j = 2; j*j<=i; j++){
			if(i%j==0){
				//zahl hat einen teiler
				teilbar=true;
			}
		}
		if(!teilbar){
			cout << i << endl;
		}
	}
}
