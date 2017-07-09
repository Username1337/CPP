#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <list>
#include <thread>
#include <condition_variable>
#include <cstdlib>

using namespace std;

template<typename T>
class set {
    unsigned int max_len;
    list<T> t_list;
    mutex* mutex_insert; //hinzugefügt durch Aufgabenteil i
    
public:
    //Aufgabenteil a
    set(unsigned int max_size) : max_len(max_size) {
        mutex_insert = new mutex(); //create new mutex for use in insert method
    }
    
    //Aufgabenteil b
    set(unsigned int max_size, const initializer_list<T>& l) : set(max_size) {
        for (auto i: l) {
            this->set_value(i);
        }
    }
    
    //Aufgabenteil c
    bool contains(T n) const {
        for(auto i: t_list) {
            if (i == n) {
                return true;
            }
        }
        return false;
    }
    
    /* Aufgabe d) vor den Änderungen durch i
    //Aufgabenteil d
    void set_value(unsigned int n) {
        if(!this->contains(n)) {
            //Aufgabenteil e
            if (t_list.size() >= max_len) {
                throw "not okay";
            }
            t_list.push_back(n);
        }
    }
    */
    
    //Aufgabenteil d) und i)
    void set_value(T n) {
        //this should do the trick, and be exception safe
        //lock gilt fuer ganzen Block, weil es schon Probleme mit dem contains geben koennte wenn 
        //jemand den Lock hat und etwas einfuegt, und wir ohne Lock pruefen ob wir ueberhaupt einfuegen muessen
        lock_guard<mutex> lk(*mutex_insert);
        if(!this->contains(n)) {
            //Aufgabenteil e
            if (t_list.size() >= max_len) {
                throw new exception();
            }
            t_list.push_back(n);
        }
    }
    
    //Aufgabenteil f
    void remove_value(T n) {
        t_list.remove(n);
    }
    
    //Aufgabenteil g
    friend set operator+(const set & s1, const set & s2) 
    {
        set result(s1.max_len + s2.max_len);
        for(auto i: s1.t_list) {
            result.set_value(i);
        }
        for(auto i: s2.t_list) {
            result.set_value(i);
        }
        return result;
    }; 
    
    //Aufgabenteil h
    friend ostream & operator<<(ostream & os, const set & s ) {
        os << "{";
        bool first = true;
        for(auto i: s.t_list) {
            if (!first) {
                os << ", ";
            }
            os << i;
            first = false;
        } 
        os << "}";
        return os;
    }
    
    //nicht gefordert, aber fuer Testzwecke hier
    size_t size() {
        return t_list.size();
    }
};

//Hilfsfunktion fuer den Test von Aufgabe i)
void paralleles_einfuegen(set<unsigned int> &s) {
    for(int i=0; i<50; i++) {
        unsigned int n = rand(); //da C++ den Speicher nicht aufraeumt, haben wir hier schon einen zufaelligen Wert ;-)
        s.set_value(n);
    }
}

int main()
{
    //1a
    cout << "A1 a):" << endl;
    set<unsigned int> s1(5);
    cout << s1 << endl << endl;
    
    //1b
    cout << "A1 b):" << endl;
    set<unsigned int> s2(7, {1, 2});
    cout << s2 << endl << endl;
    
    //1c
    cout << "A1 c):" << endl;
    cout << "1 in {1, 2}: " << s2.contains(1) << endl;
    cout << "3 in {1, 2}: " << s2.contains(3) << endl << endl;
    
    //1d
    cout << "A1 d):" << endl;
    s1.set_value(1);
    s1.set_value(2);
    s1.set_value(3);
    s1.set_value(4);
    s1.set_value(5);
    s1.set_value(1);
    cout << s1 << endl << endl;
    
    //1e
    cout << "A1 e):" << endl;
    try {
        s1.set_value(6);
        cout << "1e not okay - no exception thrown" << endl;
    } catch (...) {
        cout << "1e okay - exception thrown" << endl;
    }
    cout << endl << endl;
    
    //1f
    cout << "A1 f):" << endl;
    s1.remove_value(1);
    cout << s1 << endl << endl;
    
    //1g
    cout << "A1 g):" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 + s2:" << s1 + s2 << endl << endl;
    
    //1i
    cout << "A1 i):" << endl;
    set<unsigned int> s_parallel(100);
    thread t1(paralleles_einfuegen,ref(s_parallel));
    thread t2(paralleles_einfuegen,ref(s_parallel));
    t1.join();
    t2.join();
    
    //hoffentlich haben wir jetzt bis zu 100 verschiedene Werte 
    cout << s_parallel << endl;
    //sollten wahrscheinlich 100 sein, die Wahrscheinlichkeit 2 gleiche zu bekommen ist hier doch sehr gering
    cout << "Anzahl Werte: " << s_parallel.size() << endl << endl;
    
    //1j
    cout << "A1 j):" << endl;
    
    //probieren wir doch mal ein set von string
    set<string> string_set(3);
    cout << "leeres String-Set: " << string_set << endl;
    
    string test_string = "teststring";
    string_set.set_value(test_string);
    cout << "String-Set mit 1 Wert: " << string_set << endl;
    
    string_set.set_value(test_string);
    cout << "selber Wert nochmal eingefuegt: " << string_set << endl;
    
    string test_string2 = "noch ein string";
    string_set.set_value(test_string2);
    cout << "anderer Wert eingefuegt: " <<  string_set << endl;
    
    string_set.remove_value(test_string);
    cout << "erster Wert entfernt" << string_set << endl;
    
}
