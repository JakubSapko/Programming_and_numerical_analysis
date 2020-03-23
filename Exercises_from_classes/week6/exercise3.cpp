#include <iostream>
#include <stdlib.h>


using namespace std;

string zakoduj(string text, int skok){
	string odp = "";
	for (int i = 0; i<text.length(); i++){
		if (isupper(text[i])){
			odp += char(int(text[i]+skok-65)%26+65);}
		else{
			odp+= char(int(text[i]+skok-97)%26+97);}
	}
	return odp;
}


int main(int argc, char* argv[]){
	if (argc != 3){cout <<"Zla liczba podanych argumentow programu. Podaj poprawna";}
	else{
		string text(argv[2]);
		int skok = atoi(argv[1]);
		cout << zakoduj(text, skok);	
}

return 0;
}
