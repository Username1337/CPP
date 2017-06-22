#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bruch {
	private:
		int zaehler;
		int nenner;

	public:
		Bruch(): zaehler(1), nenner(1){
		}

		Bruch(int zaehler, int nenner): zaehler(zaehler), nenner(nenner){
		}

		Bruch(Bruch& bruch): zaehler(bruch.zaehler), nenner(bruch.nenner){
		}

		~Bruch(){
		}

		friend ostream& operator<<(ostream& os, const Bruch& b){
			os << b.zaehler << "/" << b.nenner;
			return os;
		}

		int getZaehler(){
			return this->zaehler;
		}

		void setZaehler(int zaehler){
			this->zaehler = zaehler;
		}

		int getNenner(){
			return this->nenner;
		}

		void setNenner(int nenner){
			this->nenner = nenner;
		}
};

int main(){
	Bruch a(2,3);
	Bruch b;
	Bruch c(a);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}
