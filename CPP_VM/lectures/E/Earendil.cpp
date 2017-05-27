#include <cstdlib>
#include <iostream>
using namespace std;

struct rgb {
	char r;
	char g;
	char b;
};

int main(){
	rgb a = {20,40,80};
	cout << (int)a.r << (int)a.g << (int)a.b << endl;
	cout << sizeof(a) << " und " << sizeof(rgb) << endl;

}
