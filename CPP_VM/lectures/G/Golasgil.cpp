#include <iostream>
#include <string>

using namespace std;

class Kontakt{
	private:
		string name;
		float alter;

	public:
		Kontakt(){}

		Kontakt(string name, float alter): name(name), alter(alter){}

		Kontakt(Kontakt& kontakt): name(kontakt.name), alter(kontakt.alter){}

		~Kontakt(){}

		friend ostream& operator<<(ostream& os, Kontakt& kontakt){
			os << kontakt.name << " (" << kontakt.alter << ")";
			return os;
		}

		string getName(){
			return this->name;
		}

		void setName(string name){
			this->name = name;
		}

		float getAlter(){
			return this->alter;
		}

		void setAlter(float alter){
			this->alter = alter;
		}
};

int main(){
	Kontakt b("Bernt", 35);
	Kontakt d("Dietel", 40);
	cout << b << endl;
	cout << d << endl;
	return 0;
}
