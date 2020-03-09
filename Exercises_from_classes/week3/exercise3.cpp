#include <iostream>

using namespace std;

int gcdRec(int a, int b){
	if ( a == b){return a;}
	else if (a>b){ return gcdRec(a-b, b);}
	else if (a<b){ return gcdRec(a, b-a);}
}

int main(){
//Zmienne//
int x;
int y;
//
cout << "Podaj dwie liczby calkowite dodatnie\n";
cin >> x;
cin >> y;
if (x == 0 || y == 0){cout <<"Zly input, koncze dzialanie!";}
else {cout << "NWD tych dwoch liczb to: " << gcdRec(x, y);}



return 0;
}
