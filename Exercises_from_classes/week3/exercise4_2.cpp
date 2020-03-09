#include <iostream>

using namespace std;

int gcdRec(int a, int b){ //NWD
	if ( a == b){return a;}
	else if (a>b){ return gcdRec(a-b, b);}
	else if (a<b){ return gcdRec(a, b-a);}
}

int sumDigits(int n){	//suma cyfr w liczbie
	if (n==0){return 0;}
	else{return n%10 + sumDigits(n/10);}
}	

int numDigits(int n){	//liczba cyfr w liczbie
	if (n==0){return 0;}
	else{return 1+numDigits(n/10);}
}

void printOddEven(int n){
	if (n<=0){return;}	
	printOddEven(n-2);
	cout << n << " ";
}

int gNValue(int n){
	if (n%2 == 0){return n/2;}
	else {return 3*n+1;}
}

void hailstone(int n){
	if (n == 1){cout << n << " ";}
	else{
		cout << n << " ";
		hailstone(gNValue(n));
	}
}


int main(){

cout << " gcdRec (12 , 42) = " << gcdRec (12 , 42) << endl
<< " gcdRec (12 , 25) = " << gcdRec (12 , 25) <<  endl ;
cout << " sumDigits (123) = " << sumDigits (123) <<endl
<< " sumDigits (971) = " << sumDigits (971) << endl ;
cout << " numDigits (12345) = " << numDigits (12345) 
<< " numDigits (971) = " << numDigits (971) << endl ;
cout << " printOddEven (14): ";
printOddEven (15);
cout <<  endl ;
cout << " printOddEven (14): ";
printOddEven (14);
cout << endl ;
cout << " hailstone (13): ";
hailstone (13);
cout << endl ;

return 0;}
