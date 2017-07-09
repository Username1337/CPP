#include <iostream>

using namespace std;

int main (){
	int*c = new int[4];
	c[0] = 1;
	c[1] = 3;
	c[2] = 5;
	c[3] = 7;
	c[4] = 9;
	c[5] = 9;
	c[6] = 9;
	c[7] = 9;
	c[8] = 9;
	int * d = new int[4];
	d[0] = 1;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 1;
	delete []c;
	cout <<c[2];
	return 1;
}
