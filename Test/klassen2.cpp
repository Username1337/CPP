#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Hund {
	private:
		int alter;
		string name;
		Hund* kind;
	
	public:
		Hund(){
			alter = 0;
			name = "kein name";
			/* cout << this->name << ": " << alter << endl; */
		}

		Hund(string name){
			alter = 0;
			this->name = name;
			/* cout << this->name << ": " << alter << endl; */
		}

		void altern(int jahre){
			alter += jahre;
		}

		void setName(string name){
			this->name = name;
		}

		friend ostream& operator<<(ostream& os, const Hund& c){
			os << c.name << ": " << c.alter;
			if(c.kind != nullptr){
				os << " (Kind: " << *c.kind << ")";
			}
			return os;
		}

		friend Hund* operator+(Hund& c1, Hund& c2){
			Hund* out = new Hund();
			c1.kind = out;
			c2.kind = out;
			cout << "Oh wie schön ein neuer Hund wurde geboren :)" << endl;
			return out;
		}
};

int main(){
	Hund& noname = *new Hund();
	cout << noname << endl;
	Hund& hund = *new Hund("anton");
	hund.altern(2);
	cout << hund << endl;
	Hund* hund2 = new Hund("benno");
	hund2->altern(4);
	cout << *hund2 << endl;
	Hund* kind = hund + *hund2;
	(*kind).setName("Wuffi");
	cout << hund << endl;
	cout << *hund2 << endl;
	return 0;
}
