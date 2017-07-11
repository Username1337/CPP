#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

using namespace std;

int main(){
	{
		ifstream inFile("MyLog.txt");
		//check for error
		if(inFile.fail()){
			cerr << "error opening file" << endl;
			return 1;
		}
		/* string x,y; */
		/* //every >> takes a new line ( it doesn't :/ ) */
		/* //every >> takes the next word */
		/* inFile >> x >> y; */
		/* cout << x << y; */
		//read a file until you reach the end
		string items;
		int count=0;
		stringstream ss;
		while(!inFile.eof()){
			inFile >> items;
			ss<<items;
			//items ist hier immer das aktuelle wort
			if(items=="is"){
				count++;
			}
			cout << items << " ";
			/* ++count; */
		}
		ss<<endl<<endl;
		cout <<endl<<"items: "<<count<<endl;
		cout <<items<<endl;
		cout<<"ss:";
		cout <<ss.str()<<endl;
	}
	{
		ifstream t("MyLog.txt");
		string str( (istreambuf_iterator<char>(t)), istreambuf_iterator<char>() );
		cout <<str;
	}
	{
		ofstream of("MyLog.txt");
		of << "Experience is the mother of wisdom"<<endl;
		of << "Experience is the mother of wisdom"<<endl;
		of << "Experience is the mother of wisdom"<<endl;
	}
	return 0;
}
