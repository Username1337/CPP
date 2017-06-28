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

		Queue(initializer_list<int> liste){
			for(int x: liste){
				this->elemente.push_back(x);
			}
		}

		void add(int x){
			this->elemente.push_back(x);
		}

		const Queue& operator+=(const Queue& q){
			for(int i: q.elemente){
				this->elemente.push_back(i);
			}
			return *this;
		}

		friend Queue& operator+(const Queue& links, const Queue& rechts){
			Queue* neu = new Queue(links);
			*neu+=rechts;
			return *neu;
		}

		const Queue& operator+=(const int x){
			this->elemente.push_back(x);
			return *this;
		}

		friend Queue& operator+(const Queue& links, const int x){
			Queue* neu = new Queue(links);
			*neu+=x;
			return *neu;
		}

		void print(){
			for(int x: this->elemente){
				cout << x << endl;
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
	*d+=22;
	*d+=23;
	*d+=24;
	*d+=25;
	*d+=26;
	/* d->print(); */
	Queue* q = new Queue{12,13,14,15,16};
	//TODO how to make a new object with {...} on the heap
	*q+=*d;
	q->print();
	return 0;
}
