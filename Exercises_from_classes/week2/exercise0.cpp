#include <iostream>

using namespace std;

int silnia(int n){		//Recursive way of calculating a factorial, it cycles through itself until it reaches n=1 and return a factorial
	if (n>1){ return n*silnia(n-1);}
	else {return 1;}
}

double potega(double x, int k){ //Recursive way of getting x to k-th power 
	if (k>0){
	k--;
	return x*potega(x, k);}
	else{return 1;}

}

int main(){
//Variables//
int n;
double x;
int k;
//


cout << "Provide a natural number ";
cin >> n;
while (n<0){
	cout << "This isn't a proper value for a factorial method, provide a valid natural number: "<<endl;
	cin >> n;
}
cout << endl;
cout << "Provide a real number x: ";
cin >> x;
cout << endl;
cout << "Provide a natural number k: ";
cin >> k;
cout << endl;


cout << n <<"! = " << silnia(n) << endl;
cout << x <<"^"<<k << " = " << potega(x, k);




return 0;
}
