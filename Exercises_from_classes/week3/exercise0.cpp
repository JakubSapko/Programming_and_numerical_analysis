#include <iostream>

using namespace std;

bool isPrime(int n){                           
	if (n<=1){return false;}
	for (int i = 2; i < n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;}

int main(){

//Zmienne//
int n;
//

cout << "Podaj liczbe: ";
cin >> n;
if(isPrime(n)){cout <<"Podana liczba jest pierwsza";}
else{cout << "Podana liczba nie jest pierwsza";}

return 0;
}
