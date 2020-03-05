#include <iostream>
#include <iomanip>



using namespace std;

bool isPrime(int n){                            //Function isPrime is checking if a given integer is considered a prime or not with a simplest possible algorithm for that
	if (n<=1){return false;}
	for (int i = 2; i < n; i++){				// This could be for(int i = 2; i*i<n; i++) for optimalization
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

unsigned long long int primorial(int n){  //Function primorial is responsible for a calcualtion of primorials, it loops through a given range, checks for primes with isPrime function
	int iloczyn = 1;                      //and uses those primes to calculate primorial
	for (int i=0; i <= n; i++){
		if (isPrime(i)){
			iloczyn = iloczyn*i;}
	}
	return iloczyn;
}


int main(){

cout << " N primorial(N)\n";
	for (int n = 0; n <= 53; n++){
		cout << setw(2) << n                                       //simple output manipulation for readers' sake
			 << setw(21) << primorial(n) << '\n';
	}


return 0;
}
