#include <iostream>

using namespace std;

class BasisRaumschiff {
	public:
		int Farbe;
		int Energie;

		BasisRaumschiff(){
			Farbe = 1;
			Energie = 1000;
			std::cout << "Ein neues BasisRaumschiff wurde erstellt!" << std::endl;
		}

		void Starten() {
			std::cout << "Raumschiff startet" << std::endl;
		}

		void Landen() {
			std::cout << "Raumschiff landet" << std::endl;
		}
};

class TransportRaumschiff : public BasisRaumschiff {
	public:
		int Ladung;
		int MaxLadung;

		void Laden(){
			std::cout << "Raumschiff ladet ein" << std::endl;
		}

		void Entladen(){
			std::cout << "Raumschiff lädt aus" << std::endl;
		}

		virtual void Starten(){
			std::cout << "TransportRaumschiff ladet ein" << std::endl;
		}

		virtual void Landen() {
			std::cout << "TransportRaumschiff landet" << std::endl;
		}
};

int main(){
	TransportRaumschiff s1;
	s1.Laden();
	s1.Starten();
	s1.Landen();
	s1.Entladen();
	return 0;
}
