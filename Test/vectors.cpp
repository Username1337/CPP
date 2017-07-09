#include <iostream>
#include <vector>       // containers are part of the so-called
#include <algorithm>

using namespace std;

class MyWrap{
	private:
		int x;
	public:
		MyWrap(): x(1){
		}
		MyWrap(const MyWrap& w): x(w.x){
		}
		MyWrap(const int x): x(x){
		}
		int getX() const{
			return this->x;
		}
		void setX(const int x){
			this->x = x;
		}
		friend ostream& operator<<(ostream& os, const MyWrap& w){
			os<<w.x;
			return os;
		}
		bool operator==(const MyWrap& w){
			return this->x==w.x;
		}
};

void printVector(vector<MyWrap>& v){
	for(auto el: v){
		cout << el.getX() << " ";
	}
	cout << endl;
}

int main() {
	MyWrap w1,w2,w3,w4,w5,w6;
	w1.setX(4);
	w2.setX(2);
	w3.setX(5);
	w4.setX(1);
	w5.setX(9);
	w6.setX(7);
	vector<MyWrap> v{w1,w2,w1,w3,w1,w4,w5,w6};
	printVector(v);
	cout <<"remove"<<endl;
	/* auto it = remove(v.begin(), v.end(), w1); */
	/* auto it = remove_if(v.begin(), v.end(), [=](MyWrap x){return x==w1;}); */
	/* auto it = remove_if(v.begin(), v.end(), [=](MyWrap x){return x.getX()%2;}); */
	//dann ist v danach {4.6, 7.8, 2.5, 2.5, 2.5}
	/* printVector(v); */
	/* v.erase(it, v.end()); */
	/* printVector(v); */
	v.erase(v.begin(), v.end()-2);
	printVector(v);
	return 1;
}
