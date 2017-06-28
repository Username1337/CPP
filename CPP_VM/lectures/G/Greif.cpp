#include <iostream>
#include <vector>
#include <thread>
#include <unordered_map>

using namespace std;

long fib(int n){
	/* static vector<long> map; */
	static unordered_map<long,long> map;
	long fn = map[n];
	/* long fn = 0; */
	if(fn!=0){
		return fn;
	} else if(n<2){
		return n;
	} else {
		return fib(n-1)+fib(n-2);
	}
}

int main(){
	int n=0;
	while(n>=0){
		cin >> n;
		auto t1 = std::chrono::high_resolution_clock::now();
		cout << fib(n) << endl;
		auto t2 = std::chrono::high_resolution_clock::now();
		cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms" << endl;
	}
	return 1;
}
