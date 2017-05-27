#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IReport {
	public:
		IReport(){}

		~IReport(){}

		virtual string MonatsReport() = 0;
};

class Kontakt: public IReport {
	private:
		string name;
		int alter;

	public:
		Kontakt(string name, int alter): IReport() {
			this->name = name;
			this->alter = alter;
		}

		Kontakt(const Kontakt& kontakt){
			this->name = kontakt.name;
			this->alter = kontakt.alter;
		}

		~Kontakt(){
		}

		string getName(){
			return this->name;
		}

		int getAlter(){
			return this->alter;
		}
};

class Kunde: public Kontakt {
	private:
		int kontostand;
	
	public:
		Kunde(string name, int alter, int kontostand): Kontakt(name,alter){
			this->kontostand = kontostand;
		}

		void setKontostand(int kontostand){
			this->kontostand = kontostand;
		}

		int getKontostand(){
			return this->kontostand;
		}

		string MonatsReport(){
			return "Kunden Report";
		}
};

class Lieferant: public Kontakt {
	private:
		string bankverbindung;

	public:
		Lieferant(string name, int alter, string bankverbindung): Kontakt(name,alter){
			this->bankverbindung = bankverbindung;
		}

		string getBankverbindung(){
			return this->bankverbindung;
		}

		string MonatsReport(){
			return "Lieferanten Report";
		}
};

class KontaktVerwaltung {
};

int main(){
	cout << "start" << endl;
	vector<Kontakt*> kontakte;
	Kunde* a = new Kunde("Peter", 35, 0);
	Kunde* b = new Kunde("Dieter", 40, 40);
	Lieferant* c = new Lieferant("Aldi", 7, "asdf");
	Lieferant* d = new Lieferant("Lidl", 4, "hjkl");
	kontakte.push_back(a);
	kontakte.push_back(b);
	kontakte.push_back(c);
	kontakte.push_back(d);

	for(Kontakt* kontakt: kontakte){
		cout << kontakt->MonatsReport() << endl;
	}
	return 0;
}
