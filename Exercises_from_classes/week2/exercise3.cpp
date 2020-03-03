#include <iostream>

using namespace std;


int sumDigits(int n){
	if (n>0){ return n%10 + sumDigits(n/10);}
	return 0;
}


int main(){
//Variables//
int n;
int suma;
int poprzednia;
//
/* This program asks user to give an integer number until he provides 0,
when 0 is given, program prints out this number which had a biggest sum of digits
e.g. for 123 -> 6, 65 -> 11, 0, it prints out 65
Depending on which preprocessor macro is defined, its uses either english or polish to 
communicate with user */

#if defined POL
cout << "Podaj liczbe calkowita (0 konczy dzialanie programu): ";
#endif

#if defined ENG
cout << "Provide an integer number (0 ends program): ";
#endif

cin >> n;
suma = sumDigits(n);

#if (((defined POL) && (defined ENG)) || ((!defined POL) && (!defined ENG)))
#error "Nie zdefiniowano makra jezyka lub zdefiniowano dwa rozne jezyki"
#endif

while (n!=0){
	#if defined POL
	cout << "Podaj liczbe calkowita (0 konczy dzialanie programu): ";
	#endif

	#if defined ENG
	cout << "Provide an integer number (0 ends program): ";
	#endif

	cin >> n;
	if (sumDigits(n) > suma){
		suma = sumDigits(n);
		poprzednia = n;}
}

#if defined POL
cout << "Maksymalna suma cyfr wyniosla: " << suma << ". Dla liczby: " << poprzednia;
#endif

#if defined ENG
cout << "The biggest sum of numbers' was: " << suma << ". For: " << poprzednia;
#endif	

return 0;
}
