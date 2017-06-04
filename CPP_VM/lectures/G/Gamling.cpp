#include <iostream>
using namespace std;

struct Punkte{
	int x;
	int y;
};

class Punkt{
	int x;
	int y;
	public :

	Punkt() : x(0), y(0){}

	Punkt (const Punkt& p): x(p.x), y(p.y){}

	Punkt (int x1, int x2): x(x1), y(x2){}

	Punkt (struct Punkte p) : x(p.x), y(p.y){}

	~Punkt(){
		cout << "deine Klasse wird eliminiert " << endl;
	}

	Punkt& operator=(const Punkt& p){
		this->x = p.x; this->y = p.y;
		return *this;
	}

	friend ostream& operator<<(ostream & os,  Punkt const & p){
		os << "(" << p.x << "/" << p.y << ")" ;
		return os;
	}

	int getX()const{
		return this->x;
	}

	int getY() const {
		return this->y;
	}

	void setX(int x1){
		this->x = x1;
	}

	int setY(int x2){
		this->y = x2;
	}

	int getMaxNorm(){
		if(this->x >= this->y){
			return x;
		}
		return y;
	}

};

int main(){
	Punkt p;
	Punkt p1(p);
	Punkte e;
	e.x = 14;
	e.y = 13;
	cout << p << endl;
}
