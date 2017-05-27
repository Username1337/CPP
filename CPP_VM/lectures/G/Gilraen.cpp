#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BefoerderungsMittel {
	public:
		int anzahlSitzplaetze = 0;

		BefoerderungsMittel(){
			cout << "new BefoerderungsMittel" << endl;
		}

		~BefoerderungsMittel(){
		}
};

class Fahrzeug {
	public:
		float topSpeed = 0;

		Fahrzeug(){
			cout << "new Fahrzeug" << endl;
		}

		~Fahrzeug(){
		}
};

class Auto: public virtual BefoerderungsMittel, public Fahrzeug {
	public:
		int anzahlRaeder = 4;

		Auto(): BefoerderungsMittel(), Fahrzeug() {
			cout << "new Auto" << endl;
		}

		~Auto(){
		}
};

class Boot: public virtual BefoerderungsMittel, public Fahrzeug {
	public:
		int anzahlSchiffsschrauben = 1;

		Boot(): BefoerderungsMittel(), Fahrzeug(){
			cout << "new Boot" << endl;
		}

		~Boot(){
		}
};

class Amphibie: public Auto, public Boot {
	public:
		Amphibie(): BefoerderungsMittel(), Auto(), Boot(){
			cout << "new Amphibie" << endl;
		}

		int getAnzahlSitzplaetze(){
			return this->anzahlSitzplaetze;
		}

		void setAnzahlSitzplaetze(int anzahlSitzplaetze){
			this->anzahlSitzplaetze = anzahlSitzplaetze;
		}

		float getTopSpeedAuto(){
			return Auto::topSpeed;
		}

		void setTopSpeedAuto(float topSpeed){
			Auto::topSpeed = topSpeed;
		}

		float getTopSpeedBoot(){
			return Boot::topSpeed;
		}

		void setTopSpeedBoot(float topSpeed){
			Boot::topSpeed = topSpeed;
		}

};

class FahrzeugVerwaltung {
};


int main(){
	Amphibie amphibie1;
	amphibie1.setAnzahlSitzplaetze(10);
	amphibie1.setTopSpeedAuto(180);
	amphibie1.setTopSpeedBoot(50);
	Amphibie amphibie2;
	amphibie2.setAnzahlSitzplaetze(5);
	amphibie2.setTopSpeedAuto(90);
	amphibie2.setTopSpeedBoot(30);
	cout << "Anzahl Sitzplaetze: " << amphibie1.getAnzahlSitzplaetze() << endl;
	cout << "Top Speed Auto: " << amphibie1.getTopSpeedAuto() << endl;
	cout << "Top Speed Boot: " << amphibie1.getTopSpeedBoot() << endl;
	cout << "Anzahl Sitzplaetze: " << amphibie2.getAnzahlSitzplaetze() << endl;
	cout << "Top Speed Auto: " << amphibie2.getTopSpeedAuto() << endl;
	cout << "Top Speed Boot: " << amphibie2.getTopSpeedBoot() << endl;
	return 0;
}
