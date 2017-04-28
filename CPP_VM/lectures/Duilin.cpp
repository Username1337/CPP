#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	string in;
	cin >> in;

	int i {};
	float f {};
	double d {};
	
	i=stoi(in);
	f=stof(in);
	d=stod(in);

	cout <<"i: "<<i<<"; f: "<<f<<"; d: "<<d<<endl;

	string s {};

	s=to_string(i);
	cout<<"s von i: "<<s<<endl;
	s=to_string(f);
	cout<<"s von f: "<<s<<endl;
	s=to_string(d);
	cout<<"s von d: "<<s<<endl;

}
