#include <iostream>

using namespace std;

template<typename T>
struct s_Bruch {
	T zaehler;
	T nenner;
};

template<typename T>
class Bruch {
	private:
		typedef T value_type;
		T zaehler;
		T nenner;

	public:
		Bruch(const T& zaehler, const T& nenner): zaehler(zaehler), nenner(nenner){}
		Bruch(const Bruch<T>& b): zaehler(b.zaehler), nenner(b.nenner){}
		Bruch(const s_Bruch<T>& b): zaehler(b.zaehler), nenner(b.nenner){}
		Bruch(initializer_list<T>& list): zaehler(list[0]), nenner(list[1]){}
		~Bruch(){}

		T getZaehler(){
			return this->zaehler;
		}
		
		T getNenner(){
			return this->nenner;
		}

		void setZaehler(T zaehler){
			this->zaehler = zaehler;
		}

		void setNenner(T nenner){
			this->nenner = nenner;
		}

		friend ostream& operator<<(ostream& os, const Bruch& b){
			os << b.zaehler << "/" << b.nenner;
			return os;
		}
};

int main(){
	Bruch<int> b1(2,3);
	Bruch<long> b2{4,9};
	s_Bruch<double> b{ 6,7 };
	Bruch<double> b3(b);
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return 0;
}
