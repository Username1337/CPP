#include <iostream>

using namespace std;

class Koordinaten {
	private:
		int x;
		int y;
	
	public:

		Koordinaten() : x(0), y(0){
			/* this->setX(0); */
			/* this->setY(0); */
		}

		//werte direkt zuweisen
		Koordinaten(int x, int y) : x(x), y(y){
			/* this->setX(x); */
			/* this->setY(y); */
		}

		int getX(){
			return this->x;
		}

		void setX(int x){
			this->x = x;
		}

		int getY(){
			return this->y;
		}

		void setY(int y){
			this->y = y;
		}

		void print(){
			std::cout << "X: " << this->x << std::endl;
			std::cout << "Y: " << this->y << std::endl;
		}
};

void swap(Koordinaten* a, Koordinaten* b);

int main(){
	Koordinaten a;
	Koordinaten *b = new Koordinaten();
	Koordinaten *c = new Koordinaten(2,3);

	a.setX(3);

	b->setY(4);

	swap(c,&a);

	a.print();
	//b und c sind pointer
	(*b).print();
	c->print();

	return 0;
}

void swap(Koordinaten* a, Koordinaten* b){
	Koordinaten c = *b;
	*b = *a;
	*a = c;
	std::cout << "hallo" << std::endl;
}
