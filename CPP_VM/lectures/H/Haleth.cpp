#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T> //Wasser, Bier
class Sixpack {
	private:
		typedef T value_type;

	public:
		class Flasche {
			private:
				T inhalt;		//Bier
				double menge;	//30%
			public:
				Flasche(const T& t): inhalt(t){
					this->menge=100;
				}
				Flasche& operator+=(const double menge){
					this->menge += menge;
					return *this;
				}
				Flasche& operator-=(const double menge){
					this->menge -= menge;
					return *this;
				}
				friend ostream& operator<<(ostream& os, const Flasche& f){
					os << f.inhalt << " " << f.menge;
					return os;
				}
				double getMenge(){
					return this->menge;
				}
				T getInhalt(){
					return this->inhalt;
				}
				bool istLeer(){
					return this->menge==0? true: false;
				}
		};

		vector<Flasche> sixpack;
		T inhalt;

		Sixpack(T& t): inhalt(t){
			this->sixpack.push_back(t);
			this->sixpack.push_back(t);
			this->sixpack.push_back(t);
			this->sixpack.push_back(t);
			this->sixpack.push_back(t);
			this->sixpack.push_back(t);
		}

		void trink(int flasche, double menge){
			if(flasche<=6 && flasche>=1){
				Flasche* f = &(this->sixpack[flasche-1]);
				if(f->getMenge()>0){
					if(f->getMenge()-menge<0){
						double tmp = f->getMenge();
						*f -= tmp;
						cout << "Hmm Lecker. " << tmp << " " << f->getInhalt() <<" getrunken." << endl;
					} else {
						*f -= menge;
						cout << "Hmm Lecker. " << menge << " " << f->getInhalt() <<" getrunken." << endl;
					}
					if(f->getMenge()==0){
						cout << "Diese Flasche ist jetzt auch leer :("<<endl;
					}
				} else {
					cout << "Mist. Die Flasche ist leer" << endl;
				}
			}
		}

		void trinkNaechsteVolleFlasche(double menge){
			int i = 1;
			for(Flasche f: this->sixpack){
				if(!f.istLeer()){
					this->trink(i, menge);
					return;
				}
				i++;
			}
		}

		Flasche& operator[](size_t idx){
			return this->flaschen[idx];
		}

		friend ostream& operator<<(ostream& os, const Sixpack<T>& s){
			os << s.inhalt << " ( ";
			int i = 0;
			for(Flasche f: s.sixpack){
				if(i==0){
					os<<++i<<":"<<f.getMenge();
				} else {
					os << ", " <<++i<<":"<< f.getMenge();
				}
			}
			os<<" ) "<< s.zusatz();
			return os;
		}

		bool istLeer(){
			bool leer = true;
			for(Flasche f: this->sixpack){
				if(!f.istLeer()){
					leer = false;
				}
			}
			return leer;
		}

		string zusatz() const{
			return "";
		}
};

class Getraenke {
	public:
		virtual string getName() const = 0;

		friend ostream& operator<<(ostream& os, const Getraenke& b){
			os << b.getName();
			return os;
		}
};

class Bier: Getraenke {
	private:
		vector<string> zutaten;
		string name;
	public:
		Bier(string name): Getraenke(), name(name){
			this->zutaten.push_back("Hopfen");
			this->zutaten.push_back("Malz");
		}
		string getName() const{
			return this->name;
		}
		friend ostream& operator<<(ostream& os, const Bier& b){
			os << b.getName();
			return os;
		}
};

template<>
string Sixpack<Bier>::zusatz() const {
	return "hmmm lecker";
}

int main(){
	Bier turmbrau("Turmbrau");
	Sixpack<Bier> meinPack(turmbrau);
	double menge{};
	while(!meinPack.istLeer()){
		cout << meinPack <<endl;
		cout << "Wie viel willst du als nächstes Trinken? ";
		cin >> menge;
		cout << endl;
		meinPack.trinkNaechsteVolleFlasche(menge);
		cout << endl;
	}
	cout << meinPack <<endl;
	return 0;
}
