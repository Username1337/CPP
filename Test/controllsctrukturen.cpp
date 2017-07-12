#include <iostream>

using namespace std;

void elseif(){
	if(false){
		cout << "if" << endl;
	} else if(true){
		cout << "elseif" << endl;
	} else {
		cout << "else" << endl;
	}
}

void switchcase(int x){
	switch (x){
		case 0:
			cout << 0 <<endl;
			//ohne break, macht das nächste auch noch
		case 1:
			cout << 1 <<endl;
			break;
		case 2:
		case 3:
			cout << "2 oder 3" <<endl;
			break;
		default:
			cout << "default" <<endl;
	}
}

int main(){
	elseif();
	goto label;
	switchcase(0);
	switchcase(1);
label:
	switchcase(2);
	switchcase(3);
	switchcase(4);
	return 0;
}
