#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int zakoduj(int character, int skok);

int main(int argc, char * argv[]) {
	if (argc != 3){cout <<"Zla liczba podanych argumentow programu. Podaj poprawna"; return -1;}
	else{
    	int skok = atoi(argv[1]);
    	if (skok >= 26) {
        	skok = ((skok + 26) % 26);
    	}
		int i = 0;

    	while (argv[2][i] != 0) {
        	int character = argv[2][i];
        	int new_character = zakoduj(character,skok);
        	putchar(new_character);
			i++;
    	}
    	return 0;
	}
}

int zakoduj(int character, int skok) {
    int ch = character;
    int negShift = skok;
	while(skok<-26){
		skok = skok+26;}

    if (ch >= 'a' && ch <= 'z') {
        ch = ch + skok;
        if (ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
        }

         else if(ch < 'a')
         {
            ch  = ch + 26; 
         } 

    } else if (ch >= 'A' && ch <= 'Z') {
        ch = ch + skok;
        if (ch > 'Z') {
            ch = ch - 'Z' + 'A' - 1;
        }

        else if(ch < 'A')
        {
            ch = ch + 26; 
        }

    }

    return ch;
}
