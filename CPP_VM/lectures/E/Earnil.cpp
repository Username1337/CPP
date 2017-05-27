#include <cstdlib>
#include <iostream>
using namespace std;

double glob[3];

void p_arr(double arr[], size_t len){
	for(size_t i=0; i<len; i++){
		cout << arr[i] << endl;
	}

}

int main(){
	double eins {};
	double zwei {};

	cout << "Die erste Zahl: "<<endl;
	cin >> eins;
	cout << "Die zweite Zahl: "<<endl;
	cin >> zwei;

	glob[0]=eins;
	glob[1]=zwei;
	glob[2]=eins+zwei;

	p_arr(glob, sizeof(glob)/sizeof(double));
	cout << glob[0] << ", " << glob[1] << ", " << glob[2] << endl;
}
