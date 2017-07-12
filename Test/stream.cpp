#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <vector>

using namespace std;

class Obst {
	public:
		string name;
		Obst(): name(""){}
		Obst(string s): name(s){}
		Obst(const Obst& o): name(o.name){ cout << "  copy" << o.name<<endl; }
		~Obst(){}
};

int main(){

	{
		ifstream inFile("ObstListe.txt");
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
		int count=0;
		stringstream ss;
		vector<Obst> obstKorb;
		cout << "lese file"<<endl;
		while(!inFile.eof()){
			string item;
			inFile >> item;
			ss<<item;
			Obst tmp(item);
			cout << "push back " << item << endl;
			cout << "  adresse des vectors: " << &obstKorb << endl;
			cout << "  größe des vectors: " << obstKorb.size() << endl;
			cout << "  capacity des vectors: " << obstKorb.capacity() << endl;
			obstKorb.push_back(tmp);
			//item ist hier immer das aktuelle wort
			/* if(item=="Banane"){ */
			/* 	count++; */
			/* } */
			/* cout << item << " "; */
			/* ++count; */
		}
		ss<<endl<<endl;
		cout <<endl<<"items: "<<count<<endl;
		/* cout <<"last item: "<<items<<endl; */
		cout<<"ss: "<<ss.str()<<endl;
		cout << "Obst Korb:"<<endl;
		for(Obst o: obstKorb){
			cout << "\t" <<o.name << endl;
		}
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
