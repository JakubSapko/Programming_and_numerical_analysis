#include <iostream>
#include <stdio.h>


using namespace std;

int gcdRec(int a, int b){					//Recursive way of finding a Greatest Common Divisor
	if (a == b) { return a; }
	else if(a>b) {return gcdRec(a-b, b);}
	else return gcdRec(a, b-a);
}

int sumDigits(int n){			//Recursive way of finding a sum of digits in a number, e.g. 123 -> 6
	if (n>0){ return n%10 + sumDigits(n/10);} //It uses a simple algorithm consisting of modulo and div operations
	return 0;	//Mod+Div algorithm lets for getting a single digits in a number, in which modulo gets a value of this digit, and div gets to another one
}

int numDigits(int n){	//Recursive way of finding a number of digits in a number, e.g. 123 -> 3, 65 -> 2, etc.
	if (n>0){ return 1+numDigits(n/10);}	//It uses div operation to cycle through digits in a number just like in a function above
	return 0;
}

void printOddEven(int startingValue, int n){	//Function which prints every odd and even number up to a given number n
	if (startingValue>n){ return;}
	printf("%d ", startingValue);
	printOddEven(startingValue+2, n);
}

int gNValue(int n){	//Helping function for a hailstone function, which returns next value of a Collatz's series
	if (n%2 == 0){ return n/2;}
	else{ return 3*n+1;}
}

void hailstone(int n){ //Function which prints hailstone series for a given number n
	if (n == 1){ printf(" %i", n);}
	else
	{
		printf(" %i", n);
		hailstone(gNValue(n));
	}
}


		

int main(){

hailstone(13);






return 0;
}
