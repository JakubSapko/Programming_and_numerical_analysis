#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

int main(){

	//Variables//
	int WAR_MAKS = 1000000;
	int WAR_MIN = 1;
	int zgad;
	int licznik = 0;
	string odp;
	srand(time(0));
	//
	/*This program "guesses" your number and communicates with you
	depending on which answer you give him ( "s"maller, "b"igger, "y"es)
	This isn't really guessing and random but thats what we were asked to do */
	cout << "Think of a number between 1 and 10^6." << endl;
	zgad = (WAR_MAKS-WAR_MIN)/2;
	while(licznik < 20){
		cout << "Is your number equal to: " << zgad << " ?" << endl;
		cin >> odp;
		if (odp == "s" || odp == "S"){
			WAR_MAKS = zgad;
			if(WAR_MAKS - WAR_MIN == 1){ zgad = WAR_MIN;}
			else{zgad -= (WAR_MAKS-WAR_MIN)/2;}
			licznik++;}
		if (odp == "b" || odp == "B"){
			WAR_MIN = zgad;
			if(WAR_MAKS - WAR_MIN == 1){ zgad = WAR_MAKS;}
			else{zgad += (WAR_MAKS-WAR_MIN)/2;}
			licznik++;}
		if (odp == "y" || odp == "Y"){
			break;
				}
	}
	cout << "I guessed: " << zgad << " in " << licznik << "tries."<<endl;

return 0;
}


