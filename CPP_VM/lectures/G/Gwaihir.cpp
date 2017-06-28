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

		int operator[](size_t idx){ 
			return this->elemente[idx];
		}

		void print(){
			string out = "";
			for(int x: this->elemente){
				out+=x+", ";
			}
			//Alternativen
			/* for(auto x = this->elemente.begin(); x!=this->elemente.end(); x++){ */
			/* 	cout << *x << endl; */
			/* } */
			/* for(vector<int>::iterator x = this->elemente.begin(); x!=this->elemente.end(); x++){ */
			/* 	cout << *x << endl; */
			/* } */
		}
};

int main(){
	cout << "Hallo" << endl;
	Queue* d = new Queue();
	*d+=20;
	*d+=21;
	Queue* q = new Queue{10,11};
	*q+=*d;
	/* q->print(); */
	cout << q;
	q->add(4);
	return 0;
}
