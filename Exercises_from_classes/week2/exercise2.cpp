#include <iostream>

using namespace std;

long int silnia(long int n){
	if (n>1){ return n*silnia(n-1);}
	else {return 1;}
}

long double potega(long double x, long int k){
	if (k>0){
	k--;
	return x*potega(x, k);}
	else{return 1;}

}

long double wyraz(long int n, long double x){					//This program uses modified functions from exercise0 week2, 
	return potega(-1, n) * potega(x,2*n+1) / silnia(2*n+1);			//and uses them to calculate an approximated value of sin(x)
}

long double ciag(long int n, long double x){
	if (n==0){return x;}
	else if (n>0){return wyraz(n, x)+ciag(n-1, x);}
}

int main(){
// Variables //
long int n;
long double x;
//

cout << "Provide a number n: ";
cin >> n;
cout << endl;
cout << "Provide an argument x: ";
cin >> x;
cout << endl;

cout << "Sin(" << x <<") = " << ciag(n, x) << " with accuracy to " << n << " element";




return 0;
}


