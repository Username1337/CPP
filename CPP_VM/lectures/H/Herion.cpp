#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Complex {
	private:
		typedef T value_type;
		T x;
		T y;
	
	public:
		Complex(): x(0), y(0){
		}

		Complex(T x, T y): x(x), y(y){
		}

		Complex(const Complex<T>& c): x(c.x), y(c.y){
		}

		friend ostream& operator<<(ostream& os, const Complex<T>& c){
			// 5 + 3*i
			if(c.y<0){
				os << c.x << " - " << -1*c.y << "*i";
			} else {
				os << c.x << " + " << c.y << "*i";
			}
			return os;
		}

		Complex<T>& operator+=(const Complex<T>& c){
			this->x += c.x;
			this->y += c.y;
			return *this;
		}

		friend Complex<T> operator+(const Complex<T>& a, const Complex<T>& b){
			Complex<T> out(a);
			out+=b;
			return out;
		}

		Complex<T>& operator-=(const Complex<T>& c){
			this->x -= c.x;
			this->y -= c.y;
			return *this;
		}

		friend Complex<T> operator-(const Complex<T>& a, const Complex<T>& b){
			Complex<T> out(a);
			out-=b;
			return out;
		}

		Complex<T>& operator*=(const Complex<T>& c){
			//TODO
			//(x1*x2-y1*y2) + (x1*y2 + x2*y1)*i
			//(x1*x2 - y1*y2)
			this->x = (this->x * c.x) + (this->y * c.y);
			//(x1*y2 + x2*y1)
			this->y = (this->x * c.y) + (c.x * this->y);
			return *this;
		}

		friend Complex<T> operator*(const Complex<T>& a, const Complex<T>& b){
			Complex<T> out(a);
			out*=b;
			return out;
		}

		void konjugiere(){
			this->y = -1*this->y;
		}
};

int main(){
	Complex<double> a(1,-2);
	Complex<double> b(-1.56,2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	Complex<double> c;
	c = a+b;
	cout << "a+b = " << c << endl;
	c = a-b;
	cout << "a-b = " << c << endl;
	c = a*b;
	cout << "a*b = " << c << endl;
	return 0;
}
