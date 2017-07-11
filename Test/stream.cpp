#include <iostream>
#include <fstream>

using namespace std;

int main(){
	cout << "hallow"<<endl;
	{
		ofstream of("MyLog.txt");
		of << "Experience is the mother of wisdom"<<endl;
		return 1;
	}
}
