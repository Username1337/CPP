#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

/* Allgemein: Ergaenzen Sie zwei Klassen 'Node' und 'List', wobei 'Node' ein Knoten 
 * einer verketteten Liste und 'List' die verkettete Liste von Knoten ist.
 * 
 * a) (4P) Erweitern Sie die Klasse 'Node' um zwei private Attribute: 'next' und 'word'
 *    - 'next' ist ein Zeiger auf eine Instanz von 'Node' (oder nullptr), 
 *      initialisiert mit nullptr.
 *    - 'word' ist vom Typ string und kann einen beliebigen Text enthalten.
 * 
 * b) (4P) 'Node' besitzt einen oeffentlichen Konstruktor (ctor), der einen String uebergeben 
 *    bekommt und ihn in 'word' speichert.
 * 
 * c) (4P) 'Node' besitzt einen Ausgabeoperator, der das Attribut 'word' ausgibt.
 * 
 * d) (8P) 'Node' besitzt oeffentliche getter und setter fuer 'next'.
 * 
 * e) (4P) Erweitern Sie die Klasse 'List' um ein 'root' Element, welches den Zeiger
 *    auf den ersten Knoten der Liste enthaelt (nullptr zu Beginn).
 * 
 * f) (8P) 'List' besitzt einen += Operator, der einen string uebergeben bekommt und
 *    einen weiteren Knoten zu Beginn der Liste einfuegt (Idee Beispielcode in main).
 * 
 * g) (8P) 'List' besitzt ebenfalls einen Ausgabeoperator, der die verketteten Knoten 
 *    ab root durchlaeuft und ausgibt (in main testen).
 * 
 * h) (4P) Ergaenzen Sie den Code um eine Factory-Funktion createNode, die einen dynamisch
 *    erzeugten Knoten zurueckgibt.
 * 
 * i) (4P) Modifizieren Sie die Klasse 'Node' so, dass der Konstruktor ebenfalls privat
 *    ist und kommentieren Sie dazu die 'friend' Statements ein.
 * 
 * j) (2P) Verwenden Sie statt eines getters den Dereferenzierungsoperator * um das
 *    Attribut next zurueckzugeben.
 * 
 */
class Node {
	// a) next, word
	private:
		Node* next;
		string word;

	private:
		// b) ctor
		Node(string s){
			this->word = s;
			this->next = nullptr;
			/* cout << this->word; */
		}

	public:
		// c) Ausgabeoperator
		friend ostream& operator<<(ostream& os, const Node& n){
			os << n.word;
			return os;
		}

		// fuer i)
		friend Node* createNode(const string& word);
		friend class List;

		// d) getter und setter
		Node* getNext(){
			return this->next;
		}

		void setNext(Node* n){
			this->next = n;
		}

		string getWord(){
			return this->word;
		}

		friend Node* operator*(Node& n){
			return n.next;
		}

};

// h)
Node* createNode(const string& word) {
	Node* tmp = new Node(word);
	return tmp;
}

class List {
	// e) root
	private:
		Node* root;

	public:
		List(){
			this->root = nullptr;
		}

		// f) op+=
		friend List& operator+=(List& l, string s){
			Node* n = createNode(s);
			n->setNext(l.root);
			l.root = n;
			return l;
		}

		// g) Ausgabeoperator
		friend ostream& operator<<(ostream& os, const List& l){
			os << "[";
			for(Node* n = l.root; n!=nullptr; n=**n ){
				os << " " << n->getWord();
			}
			os << " ]";
			return os;
		}
};

int main() {
	List l;

	l += "class";
	l += "hello";

	/* erwartet: "[ hello class ]" */
	cout << "[ " << l << "]" << endl;

	return EXIT_SUCCESS;
}

