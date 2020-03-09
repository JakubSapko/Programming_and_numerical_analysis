#include <iostream>

using namespace std;

void rekur(){
	int n;
	cin >> n;
	if (n==0){return;}
	else{ 
		rekur();
		cout << n << " ";
	}
}


int main(){

rekur();

return 0;
}
