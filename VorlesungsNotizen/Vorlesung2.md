# lambdas

# smart pointer
<!-- delete p; -->
<!-- smart pointer -->
<!-- 	- `#include <memory>` -->
<!-- 	- wenn man ein (pointer)objekt am ende des scopes löscht, dann kann es sein, dass man vorher schon durch ein throw raus fliegt -->
<!-- 	- dann wird das objekt hinter dem pointer nicht gelöscht -->
<!-- 	//unique_ptr ist eine lokale variable und dort wird der destructor aufgerufen am ende des scope -->
<!-- 	//verhält sich wie ein normaler zeiger (*p1 / p1->) -->
<!-- 	- unique_ptr<C> p1(new C(4)); -->
<!-- 		- löscht den pointer im scope -->
<!-- 		- danach kann kein anderer diesen pointer nutzen -->
<!-- 	unique_ptr<C> p2; -->
<!-- 	p2 = move(p1) //verschiebt das objekt von p1 nach p2 -->
<!-- 	p1.get() //gibt den zeiger zu dem objekt zurück -->
<!-- 	*p1 //gibt das objekt selber zurück -->

<!-- shared pointer -->
<!-- 	- `#include <memory>` -->
<!-- 	- wenn man einen zeiger teilen will -->
<!-- 	- `shared_ptr<C> s` -->
<!-- 	- `s.reset() //löscht s` -->
<!-- 		- wenn es das letzte shared_ptr ist, welches den pointer hat, dann löscht es auch den pointer -->
vibrint nutzen


# Threads
<!-- - wenn man ein programm startet, wird der main thread gestartet -->
<!-- - bei mehreren kernen laufen die threads parallel ab -->
<!-- - beim kompilieren -pthread anhängen -->
<!-- - thread führt funktion aus -->
<!-- ``` -->
<!-- void Work(int sec){ -->
<!-- 	this_thread::sleep_for(chrono::seconds(sec)); -->
<!-- } -->
<!-- thread t1(Work, 1); -->
<!-- thread t2(Work, 2); -->
<!-- thread t3([](){ this_thread::sleep_for(chrono::seconds(2)); }); //mit lambda -->
<!-- t2.join(); -->
<!-- //wait for t2 -->
<!-- t1.join(); -->
<!-- //all done -->
<!-- ``` -->

<!-- - threads mit referenzen aufrufen -->
<!-- ``` -->
<!-- void Work(int& sec){ -->
<!-- 	this_thread::sleep_for(chrono::seconds(sec)); -->
<!-- } -->
<!-- thread t1(Work, ref(4)); -->
<!-- ``` -->

<!-- - kritische regionen -->
<!-- - `#include <condition_variable>` -->
<!-- ``` -->
<!-- mutex_sum->lock(); -->
<!-- (*sum) += inc; -->
<!-- mutex_sum->unlock(); -->
<!-- ``` -->
<!-- - wenn dazwischen ein error geworfen wird, dann wird es nicht geunlocked (exception safe) -->
<!-- ``` -->
<!-- lock_guard<mutex> lk(*mutex_sum); -->
<!-- (*sum) += inc; -->
<!-- ``` -->




<!-- - `#include <chrono>` -->
<!-- - `#include <set>` -->
<!-- 	- Es gibt keine dopelten Elemente. -->
<!-- 	- how to use: -->
<!-- 	```cpp -->
<!-- 	set<int> s = {1,2,3}; -->
<!-- 	s.insert(3); -->
<!-- 	s.size(); -->
<!-- 	``` -->

<!-- - `#include <vector>` -->
<!-- 	- how to use -->
<!-- 	``` -->
<!-- 	vector<int> v; -->
<!-- 	vc.push_back(3); -->
<!-- 	``` -->

<!-- - `#include <limits>` -->
<!-- 	- how to use -->
<!-- 	``` -->
	
<!-- 	``` -->

<!-- - `#include <cmath>` -->
<!-- 	- how to use -->
<!-- 	``` -->
	
<!-- 	``` -->

<!-- - `#include <unordered_map>` -->
<!-- 	- how to use -->
<!-- 	``` -->
<!-- 	static unordered_map<long,long> map; -->
<!-- 	``` -->
