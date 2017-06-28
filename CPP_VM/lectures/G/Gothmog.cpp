#include <iostream>
#include <vector>
#include <thread>
#include <unordered_map>

using namespace std;

long f(int n){
	static unordered_map<long,long> sammlung;
	long fn = sammlung[n];
	if(fn!=0){
		return fn;
	}
	if(n==-1){
		return 0;
	} else if(n<=1){
		return 1;
	} else {
		return f(n-1);
	}
}

//fakultät:
//3! = 1*2*3 = 6
//4 -> 24
//5 -> 120
//6 -> 720
//7 -> 5040
//8 -> 40320
//9 -> 362880
//10 -> 3628800
//11 -> 39916800
//12 -> 479001600
//13 -> 6227020800
//14 -> 87178291200
//15 -> 1307674368000
//16 -> 20922789888000
//17 -> 355687428096000
//18 -> 6402373705728000
//19 -> 121645100408832000
//20 -> 2432902008176640000

int main(){
	int n=0;
	while(n>=0){
		cin >> n;
		auto t1 = chrono::high_resolution_clock::now();
		cout << f(n) << endl;
		auto t2 = chrono::high_resolution_clock::now();
		cout << "time: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << "ms" <<endl;
	}
	return 0;
}
