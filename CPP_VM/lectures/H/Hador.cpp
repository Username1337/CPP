#include <iostream>

using namespace std;

template<typename T>
struct Punkte{
	T x;
	T y;
};

template<typename T>
class Punkt {
	private:
		typedef T value_type;

		T x;
		T y;
	
	public:
		Punkt(T x, T y): x(x), y(y){}

		Punkt(const Punkt<T>& p): x(p.x), y(p.y){}

		Punkt(struct Punkte<T>& p): x(p.x), y(p.y){}

		~Punkt(){}

		friend ostream& operator<<(ostream & os, const Punkt<T>& p){
			os << "("<<p.x<<","<<p.y<<")";
			return os;
		}

		int getX() const {
			return this->x;
		}

		int getY() const {
			return this->y;
		}

		void setX(const T& x){
			this->x = x;
		}

		void setY(const T& y){
			this->y = y;
		}
};

int main(){
	Punkt<int> p(2,3);
	cout <<p <<endl;
	return 0;
}
