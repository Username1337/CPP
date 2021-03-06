#include <iostream>
#include <vector>

using namespace std;

class Queue {
	private:
		vector<int> elemente;

	public:
		Queue(){
		}

		Queue(const Queue& old){
			for(int x: old.elemente){
				this->elemente.push_back(x);
			}
		}

		Queue(const initializer_list<int>& liste){
			for(int x: liste){
				this->elemente.push_back(x);
			}
		}

		bool operator==(const Queue& rechts){
			return this->elemente == rechts.elemente;
		}

		bool operator!=(const Queue& rechts){
			return !(*this==rechts);
		}

		Queue& operator+=(const Queue& q){
			for(int i: q.elemente){
				this->elemente.push_back(i);
			}
			return *this;
		}

		friend const Queue& operator+(const Queue& links, const Queue& rechts){
			Queue* neu = new Queue(links);
			*neu+=rechts;
			return *neu;
		}

		Queue& operator+=(const int x){
			this->elemente.push_back(x);
			return *this;
		}

		friend const Queue& operator+(const Queue& links, const int x){
			Queue* neu = new Queue(links);
			*neu+=x;
			return *neu;
		}

		void add(int x){
			this->elemente.push_back(x);
		}

		int& operator[](size_t idx){ 
			return this->elemente[idx];
		}

		void print(){
			cout << *this << endl;
		}

		friend ostream& operator<<(ostream& os, const Queue& q){
			os << "[";
			bool first = true;
			for(int x: q.elemente){
				if(first){
					first = false;
				} else {
					os << ", ";
				}
				os << x;
			}
			os << "]";
			return os;
		}
};

int main(){
	cout << "Hallo" << endl;
	Queue* d = new Queue();
	*d+=20;
	*d+=21;
	Queue* q = new Queue{10,11};
	*q+=*d;
	cout << "q[1]: " << (*q)[1] << endl;
	(*q)[1] = 3;
	cout << "q[1]: " << (*q)[1] << endl;

	cout << *q;

	return 127;
}
