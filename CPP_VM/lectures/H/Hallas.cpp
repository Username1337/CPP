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

		/**
		 * normalisiert den Bruch, funktioniert aber nur bei types, welche den % operator haben
		 **/
		void normalisiere(){
			T ggt = this->getGGT();
			this->nenner /= ggt;
			this->zaehler /= ggt;
		}

	public:
		Bruch(): zaehler(1), nenner(1){}
		Bruch(const T& zaehler, const T& nenner): zaehler(zaehler), nenner(nenner){}
		Bruch(const Bruch<T>& bruch): Bruch(bruch.zaehler, bruch.nenner){}
		/* Bruch(initializer_list<T>& list): zaehler(list[0]), nenner(list[1]){} */
		Bruch(const initializer_list<T>& l): Bruch(*(l.begin()),*(l.end()-1)){}
		Bruch(const s_Bruch<T>& b): zaehler(b.zaehler), nenner(b.nenner){}

		~Bruch(){}

		Bruch<T>& invertiere(){
			T tmp = new T(this->zaehler);
			this->zaehler = this->nenner;
			this->nenner = *tmp;
			return *this;
		}

		static Bruch<T>& getInverse(Bruch<T> b){
			Bruch* out = new Bruch(b);
			out->invertiere();
			return *out;
		}

		T getGGT(){
			return 1;
		}

		friend ostream& operator<<(ostream& os, const Bruch<T>& b){
			os << b.zaehler << "/" << b.nenner;
			return os;
		}

		/**
		 * Bruch *= Bruch
		 **/
		Bruch<T>& operator*=(const Bruch<T>& rechts){
			this->zaehler *= rechts.zaehler;
			this->nenner *= rechts.nenner;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator/=(const Bruch<T>& rechts){
			//bruch umdrehen
			T tmp = this->zaehler;
			this->zaehler = this->nenner;
			this->nenner = tmp.zaehler;
			this *= rechts;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator+=(const Bruch<T>& rechts){
			this->nenner *= rechts.nenner;
			this->zaehler *= rechts.nenner;
			this->zaehler += rechts.zaehler*rechts.nenner;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator-=(const Bruch<T>& rechts){
			this->nenner *= rechts.nenner;
			this->zaehler *= rechts.nenner;
			this->zaehler -= rechts.nenner * rechts.zaehler;
			this->normalisiere();
			return *this;
		}

		/**
		 * Bruch *= T
		 **/
		Bruch<T>& operator*=(const T& rechts){
			this->zaehler *= rechts;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator/=(const T& rechts){
			//bruch umdrehen
			this->nenner *= rechts;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator+=(const T& rechts){
			this->zaehler += this->nenner*rechts;
			this->normalisiere();
			return *this;
		}
		Bruch<T>& operator-=(const T& rechts){
			this->zaehler -= this->nenner*rechts;
			this->normalisiere();
			return *this;
		}

		/**
		 * Bruch * Bruch
		 **/
		friend const Bruch<T>& operator*(const Bruch<T>& links, const Bruch<T>& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) *= rechts;
			return *out;
		}
		friend const Bruch<T>& operator/(const Bruch<T>& links, const Bruch<T>& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) /= rechts;
			return *out;
		}
		friend const Bruch<T>& operator+(const Bruch<T>& links, const Bruch<T>& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) += rechts;
			return *out;
		}
		friend const Bruch<T>& operator-(const Bruch<T>& links, const Bruch<T>& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) -= rechts;
			return *out;
		}

		/**
		 * Bruch * T
		 **/
		friend const Bruch<T>& operator*(const Bruch<T>& links, const T& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) *= rechts;
			return *out;
		}
		friend const Bruch<T>& operator/(const Bruch<T>& links, const T& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) /= rechts;
			return *out;
		}
		friend const Bruch<T>& operator+(const Bruch<T>& links, const T& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) += rechts;
			return *out;
		}
		friend const Bruch<T>& operator-(const Bruch<T>& links, const T& rechts){
			Bruch<T>* out = new Bruch(links);
			(*out) -= rechts;
			return *out;
		}

		/**
		 * T * Bruch
		 **/
		friend const Bruch<T>& operator*(const T& links, const Bruch<T>& rechts){ return rechts*links; }
		friend const Bruch<T>& operator/(const T& links, const Bruch<T>& rechts){ return Bruch::getInverse(rechts)*=links; }
		friend const Bruch<T>& operator+(const T& links, const Bruch<T>& rechts){ return rechts+links; }
		friend const Bruch<T>& operator-(const T& links, const Bruch<T>& rechts){ return (rechts-links)*=(-1); }

		/**
		 * Getter/Setter
		 **/
		T getZaehler(){ return this->zaehler; }
		T getNenner (){ return this->nenner;  }
		void setZaehler(T zaehler){ this->zaehler = zaehler; }
		void setNenner (T nenner) { this->nenner  = nenner;  }

};

template<>
int Bruch<int>::getGGT(){
	int max;
	//wenn negativ, mache positiv
	int zaehler = this->zaehler;
	int nenner = this->nenner;
	if(zaehler<0){
		zaehler *= -1;
	}
	if(nenner<0){
		nenner *= -1;
	}
	//bis zur groesseren zahl
	if(nenner<zaehler){
		max=nenner;
	} else {
		max=zaehler;
	}
	//groessten gemeinsamen teiler
	int ggt=1;
	for(int i = 1; i<=max; i++){
		if(this->nenner%i==0 && this->zaehler%i==0){
			ggt=i;
		}
	}
	return ggt;
}


/*
 * Spezialisierung??
 */
/* Bruch(double komma){ */
/* 	for(int nenner = 1; fmod(komma,10)==0; komma*=10, nenner*=10){ */
/* 		this->nenner = nenner; */
/* 		this->zaehler = static_cast<int>(komma); */
/* 	} */
/* } */

int main(){
	Bruch<int> b1(2,3);
	Bruch<long> b2{4,9};
	s_Bruch<double> b{ 6.5,7 };
	Bruch<double> b3(b);
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return 0;
}
