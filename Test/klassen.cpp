#include <iostream>
#include <iomanip>

using namespace std;

class Krieger {
	private:
		int leben;
		int kraft;
		int level;

	public:
		void ZeigeInfos();

		// Konstruktor
		Krieger(){
			leben = 10;
			kraft = 1;
			level = 1;
		}

		// Destruktor
		~Krieger(){
			std::cout << "Aua!!" << std::endl;
		}
};


int main(){
	Krieger k;
	k.ZeigeInfos();
	return 0;
}

//Überschreiben von funktionen (?) nach dem eigentlichen Code
void Krieger::ZeigeInfos(){
	std::cout << "Leben: " << leben << std::endl;
	std::cout << "Kraft: " << kraft << std::endl;
	std::cout << "Level: " << level << std::endl;
}
