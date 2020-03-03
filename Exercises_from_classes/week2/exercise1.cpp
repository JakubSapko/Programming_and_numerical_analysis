#include <iostream>
#include <cmath>



using namespace std;

int binaryToDecimal(long long n){		//Function which processes a binary number to decimal one,

	int deci = 0;
	int i = 0;
	int reszta;
	while(n != 0){
		reszta = n%10;				
		n /= 10;
		deci += reszta*pow(2, i);
		++i;
	}
	return deci;

}

int main(){
//Variables//
long long n;
//

cout << "Provide a number in binary: ";
cin >> n;
cout << endl;
cout << "The same number but in decimal is: " << binaryToDecimal(n);
return 0;
}


