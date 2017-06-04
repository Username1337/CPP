#include <iostream>
#include <vector>

using namespace std;

class Complex {
	private:
		double x;
		double y;
	
	public:
		Complex(): x(0), y(0){
		}

		Complex(double x, double y): x(x), y(y){
		}

		Complex(const Complex& c): x(c.x), y(c.y){
		}

		friend ostream& operator<<(ostream& os, const Complex& c){
			// 5 + 3*i
			if(c.y<0){
				os << c.x << " - " << -1*c.y << "*i";
			} else {
				os << c.x << " + " << c.y << "*i";
			}
			return os;
		}

		Complex& operator+=(const Complex& c){
			this->x += c.x;
			this->y += c.y;
			return *this;
		}

		friend Complex operator+(const Complex& a, const Complex& b){
			Complex out(a);
			out+=b;
			return out;
		}

		Complex& operator-=(const Complex& c){
			this->x -= c.x;
			this->y -= c.y;
			return *this;
		}

		friend Complex operator-(const Complex& a, const Complex& b){
			Complex out(a);
			out-=b;
			return out;
		}

		Complex& operator*=(const Complex& c){
			//TODO
			//(x1*x2-y1*y2) + (x1*y2 + x2*y1)*i
			//(x1*x2 - y1*y2)
			this->x = (this->x * c.x) + (this->y * c.y);
			//(x1*y2 + x2*y1)
			this->y = (this->x * c.y) + (c.x * this->y);
			return *this;
		}

		friend Complex operator*(const Complex& a, const Complex& b){
			Complex out(a);
			out*=b;
			return out;
		}

		void konjugiere(){
			this->y = -1*this->y;
		}
};

int main(){
	Complex a(1,-2);
	Complex b(-2,2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	Complex c;
	c = a+b;
	cout << "a+b = " << c << endl;
	c = a-b;
	cout << "a-b = " << c << endl;
	c = a*b;
	cout << "a*b = " << c << endl;
	return 0;
}
