#include <iostream>

using namespace std;

int main(){

int a; 
int l_ma = 0; 
int l_mi = 0; 
int ma = INT_MIN; 
int mi = INT_MAX; 

while(true){
	cout << "Podaj liczbe calkowita: ";
	cin >> a;	
	if (a == 0){break;}
	else{
		if (a > ma) { 
			l_ma = 0;
			ma = a;
			}
		if (a < mi) { 
			l_mi = 0;
			mi = a;}
		if (a == ma){l_ma++;}  
		if (a == mi){l_mi++;}
		}


}
cout << "Najwieksza podana liczba to: " << ma << " ktora pojawila sie: " << l_ma << " razy." << endl;
cout << "Najmniejsza podana liczba to: " << mi <<" ktora pojawila sie: " << l_mi << " razy." << endl;
return 0;
}
