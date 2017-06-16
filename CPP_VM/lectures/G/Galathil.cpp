#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Bruch {
	private:
		int zaehler;
		int nenner;

		void normalisiere(){
			int ggt = this->getGGT();
			this->nenner /= ggt;
			this->zaehler /= ggt;
		}

	public:
		Bruch(): zaehler(1), nenner(1){
		}

		Bruch(int zaehler, int nenner): zaehler(zaehler), nenner(nenner){
			this->normalisiere();
		}

		Bruch(double komma){
			for(int nenner = 1; fmod(komma,10)==0; komma*=10, nenner*=10){
				this->nenner = nenner;
				this->zaehler = static_cast<int>(komma);
			}
		}

		Bruch(Bruch& bruch): Bruch(bruch.zaehler, bruch.nenner){
		}

		Bruch(const initializer_list<int>& l): Bruch(*(l.begin()),*(l.end()-1)){
		}

		~Bruch(){
		}

		friend ostream& operator<<(ostream& os, const Bruch& b){
			os << b.zaehler << "/" << b.nenner;
			return os;
		}

		friend Bruch operator*(Bruch& b1, Bruch& b2){
			Bruch out(b1);
			out.zaehler *= b2.zaehler;
			out.nenner *= b2.nenner;
			out.normalisiere();
			return out;
		}

		friend Bruch operator/(Bruch& b1, Bruch& b2){
			//TODO
			Bruch out(b2);
			out.zaehler = b2.nenner;
			out.nenner = b2.zaehler;
			out = b1*out;
			return out;
		}

		friend Bruch operator+(Bruch& b1, Bruch& b2){
			Bruch out(b1);
			out.nenner *= b2.nenner;
			out.zaehler *= b2.nenner;
			out.zaehler += b2.zaehler*b1.nenner;
			out.normalisiere();
			return out;
		}

		friend Bruch operator-(Bruch& b1, Bruch& b2){
			Bruch out(b1);
			out.nenner *= b2.nenner;
			out.zaehler *= b2.nenner;
			out.zaehler -= b2.zaehler*b1.nenner;
			out.normalisiere();
			return out;
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

		int getGGT(){
			int max;
			//wenn negativ, mache positiv
			int zaehler = this->zaehler;
			int nenner = this->nenner;
			if(zaehler<0){
				zaehler *= -1;
			}
			if(nenner<0){
				nenner *= -1;
			}
			//bis zur groesseren zahl
			if(nenner<zaehler){
				max=nenner;
			} else {
				max=zaehler;
			}
			//groessten gemeinsamen teiler
			int ggt=1;
			for(int i = 1; i<=max; i++){
				if(this->nenner%i==0 && this->zaehler%i==0){
					ggt=i;
				}
			}
			return ggt;
		}
};

int main(){
	Bruch a(2,8);
	Bruch b(1,2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	Bruch c;
	c = a*b;
	cout << "a*b = " << c << endl;
	c = a+b;
	cout << "a+b = " << c << endl;
	c = a-b;
	cout << "a-b = " << c << endl;
	c = a/b;
	cout << "a/b = " << c << endl;
	return 0;
}
