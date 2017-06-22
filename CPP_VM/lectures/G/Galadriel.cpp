#include <iostream>
#include <vector>
using namespace std;

struct Punkte{
	int x;
	int y;
};

class Punkt{
	int x;
	int y;

	public:

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

	Punkt& operator+=(const Punkt& p){
		this->x += p.x;
		this->y += p.y;
		return *this;
	}

	friend Punkt operator+(const Punkt& p1, const Punkt& p2){
		Punkt out(p1);
		out += p2;
		return out;
	}

	Punkt& operator-=(const Punkt& p){
		this->x -= p.x;
		this->y -= p.y;
		return *this;
	}

	friend Punkt operator-(const Punkt& p1, const Punkt& p2){
		Punkt out(p1);
		out -= p2;
		return out;
	}

	friend int operator*(const Punkt& p1, const Punkt& p2){
		return p1.x*p2.x + p1.y*p1.y;
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

	void setY(int x2){
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
	string z;
	string y;
	cout << "z: ";
	cin >> y;
	cout << "y: ";
	cin >> z;
	cout << "z: "<<z<<" y: " << y << endl;
	Punkt p(3,4);
	Punkt p1(p);
	cout << p << endl;
	cout << p1 << endl;
	p+=p1;
	cout << p << endl;
	p-=p1;
	cout << p << endl;
	p=p+p1;
	cout << p << endl;
	p=p-p1;
	cout << p << endl;
	int x = p*p1;
	cout << x << endl;
	/* Punkte e; */
	/* e.x = 14; */
	/* e.y = 13; */
	return 0;
}

