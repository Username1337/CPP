#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
class LinkedList {
	private:
		typedef T value_type;

	public:
		class Node{
			private:
				T el;
				Node* next;
				Node* prev;
			public:
				/* Node(): el(), next(nullptr), prev(nullptr){ cout<<"Node ctor std"<<endl; } */
				Node(const T& el): el(el), next(nullptr), prev(nullptr){}
				Node(const Node& n): el(&n.el), next(&n.next), prev(&n.prev){}
				~Node(){}
				const T& operator*()const{
					return this->el;
				}
				Node* getNext()const{ return this->next; }
				Node* getPrev()const{ return this->prev; }
				void setNext(Node* n){ this->next=n; }
				void setPrev(Node* n){ this->prev=n; }
				friend ostream& operator<<(ostream& os, const Node& n){
					os << (n.el);
					return os;
				}
				bool operator==(const Node& rechts){
					return (this == &rechts);
				}
				bool operator!=(const Node& rechts){
					return !(this==rechts);
				}
		};

	private:
		Node* first;
		Node* last;

	public:
		LinkedList(): first(nullptr), last(nullptr){}
		LinkedList(const LinkedList<T>& ll): first(ll.first), last(ll.last){}
		~LinkedList(){
			for(const Node* current = this->first; current!=nullptr; current=current->getNext()){
				if(current->getPrev()!=nullptr){
					delete (current->getPrev());
				}
			}
			delete this->last;
		}
		/* LinkedList(const initializer_list<T> l){ ... } */

		void append(const T& el){
			Node* n = new Node(el);
			if(this->first==nullptr || this->last==nullptr){
				//keine elemente
				this->first = n;
				this->last = n;
			} else {
				//gehe zu letztem element
				Node* tmp = this->last;
				//das letzte ist das vorletzte
				tmp->setNext(n);
				n->setPrev(tmp);
				this->last = n;
			}
		}

		LinkedList<T>& operator+=(const T& rechts){
			this->append(rechts);
			return *this;
		}

		const T& operator[](int index)const{
			int i = 0;
			for(const Node* current = this->first; current!=nullptr; current=current->getNext()){
				if(index == i){
					return **current;
				}
				++i;
			}
			throw 30;
		}

		void remove(int index){
			if(this->first == nullptr){
				throw 30;
			}
			//remove first element
			if(index==0){
				this->first = this->first->getNext();
				this->first->setPrev(nullptr);
				return;
			}
			int i = 0;
			for(Node* current = this->first; current!=nullptr; current=current->getNext()){
				if(i==index){
					//remove last element
					if(*current==*this->last){
						cout << "delete last" <<endl;
						this->last = this->last->getPrev();
						this->last->setNext(nullptr);
						return;
					}
					//remove some other
					current->getPrev()->setNext(current->getNext());
					current->getNext()->setPrev(current->getPrev());
					int* i = new int(4);
					delete i;
					delete current;
					return;
				}
				++i;
			}
			throw 30;
		}

		friend ostream& operator<<(ostream& os, const LinkedList& ll){
			os << "[";
			for(const Node* current = ll.first; current!=nullptr; current=current->getNext()){
				if(current==ll.last){
					os << **current;
				} else {
					os << **current<<",";
				}
			}
			/* for(auto a: this->first) */
			os << "]";
			return os;
		}
};

int main(){
	LinkedList<int> l1;
	int a = 4;
	l1.append(a);
	l1+=6;
	l1+=3;
	l1+=88;
	cout << l1 << endl;
	l1.remove(0);
	/* LinkedList<int> l2(l1); */
	cout << l1 << endl;
	cout << l1[1]<<endl;
	return 0;
}
