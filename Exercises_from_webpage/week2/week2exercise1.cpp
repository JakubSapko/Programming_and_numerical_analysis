#include <iostream>

using namespace std;

int main(){

int a; 
int l_ma = 0; //Counter for the biggest appearing number
int l_mi = 0; //Counter for the smallest appearing number
int ma = INT_MIN; //Setting a maximum value to a minimum possible integer value so that you can always find a maximum
int mi = INT_MAX; //Same here

while(true){
	cout << "Provide an integer number: ";
	cin >> a;	
	if (a == 0){break;}
	else{
		if (a > ma) { //Resetting the biggest number and its' counter if the one provided is bigger than the actual one
			l_ma = 0;
			ma = a;
			}
		if (a < mi) { //Same here
			l_mi = 0;
			mi = a;}
		if (a == ma){l_ma++;} // Increasing a maximum counters' value 
		if (a == mi){l_mi++;} // Increasing a minimum counters' value
		}


}
cout << "The biggest provided number is: " << ma << " which appeared: " << l_ma << " times." << endl;
cout << "The smallest provided number is: " << mi <<" which appeared: " << l_mi << " times." << endl;
return 0;
}
