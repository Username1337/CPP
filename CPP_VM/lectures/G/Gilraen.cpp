#include <iostream>
#include <string>
#include <vector>

class BefoerderungsMittel {
	public:
		int anzahlSitzplaetze;

		BefoerderungsMittel(){
		}

		~BefoerderungsMittel(){
		}
};

class Fahrzeug {
	public:
		float topSpeed;

		Fahrzeug(){
		}

		~Fahrzeug(){
		}
};

class Auto: public virtual BefoerderungsMittel, public Fahrzeug {
	public:
		int anzahlRaeder;

		Auto(): BefoerderungsMittel(), Fahrzeug() {
		}

		~Auto(){
		}
};

class Boot: public virtual BefoerderungsMittel, public Fahrzeug {
	public:
		int anzahlSchiffsschrauben;

		Boot(): BefoerderungsMittel(), Fahrzeug(){
		}

		~Boot(){
		}
};

class Amphibie: public Auto, public Boot {
	public:
		Amphibie(): BefoerderungsMittel(), Auto(), Boot(){
		}
};

class FahrzeugVerwaltung {
};


int main(){
	return 0;
}
