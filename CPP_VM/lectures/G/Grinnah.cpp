#include <iostream>
#include <vector>

using namespace std;

class Queue {

	class myiterator{
		private:
			const Queue& queue;
			size_t index;

		public:
			myiterator(const Queue& _d, size_t _index): queue(_d), index(_index) {}

			bool operator!=(const myiterator& rechts) const{
				bool gleiche_element_liste = ( &(this->queue.elemente) == &(rechts.queue.elemente) );
				bool nicht_gleiche_indizes = (this->index != rechts.index);
				return gleiche_element_liste && nicht_gleiche_indizes;
			}

			double operator*() const{
				return queue.elemente[index];
			}

			const myiterator& operator++(){
				this->index++;
				return *this;
			}
	};

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

		myiterator begin() const {
			return myiterator(*this, 0);
		}

		myiterator end(){
			return myiterator(*this, this->elemente.size());
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

	for(auto x: (*q)){
		cout << x << endl;
	}

	/* cout << *q; */

	return 127;
}
