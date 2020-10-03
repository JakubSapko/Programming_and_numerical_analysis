#include <iostream> //nie wolno spacji przed >
#include <cmath>

using namespace std;

void wypisz(char* wsk, size_t rozmiar)
{
	cout << "[";
	for(int ii=0; ii<rozmiar; ii++)
	{
	//arytmetyka wskaznikow
	cout << *(wsk+ii);
	if(ii < rozmiar-1)
	cout << ", ";
	}
	cout << "]" << endl;
}

void przestaw(char* pa, char* pb, const unsigned n)
{
	//zaczynamy od sparwdzenia czy nie ma nullptr
	if(pa && pb)
	{
		int diff = pb-pa;
		// jezeli pa wskazuje na element dalszy niz pb to diff<0
		int sgn = 0;
		if(diff > 0)
			sgn = 1;
		else
			sgn=-1;

		char* orig = new char[abs(diff)+1]; //przepisujemy wartosci od pa do ob
		for(int ii=0; ii < abs(diff)+1; ii++)
		{
			orig[ii] = *(pa + ii * sgn);
		}

		int nn = n%(abs(diff)+1); //przypadek gdy n jest wieksze niz liczba elementow

		for(int jj=0; jj <  abs(diff)+1; jj++)
		{
			int index = (abs(diff) +1 - nn + jj)%(abs(diff)+1); //indeks nowej wartosci
			*(pa + jj*sgn) = orig[ index ];  //podmiana
		}
		delete[] orig; //zwolnienie pamieci
	}
	else
		cout << "Wskaznik jest pusty!" << endl;
		

}

int main()
{
	char tab[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l'};
	cout << "Tablica:" << endl;
	wypisz(tab, 12);
	cout << "Przesuwamy w prawo o 2 od tab[3] do tab[10] " << endl;
	przestaw(tab+3, &tab[11]-1, 2);
	wypisz(tab, 12);
	cout << "Przesuwamy w lewo o 2 od tab[10] do tab[3] " << endl;
	przestaw( &tab[11]-1, tab+3, 2);
	wypisz(tab, 12);
	cout << "Przesuwamy w lewo o 13 cala tablice " << endl;
	przestaw( &tab[11], tab, 13);
	wypisz(tab, 12);
	cout << "Przesuwamy w lewo o 0 cala tablice " << endl;
	przestaw( &tab[11], tab, 0);
	wypisz(tab, 12);
	cout << "Przesuwamy w prawo o 1 od tab[5] do tab[11]" << endl;
	przestaw( &tab[5], &tab[11], 1);
	wypisz(tab, 12);
	cout << "Proba uzycia nullptr" << endl;
	przestaw( &tab[5], nullptr, 1);
	wypisz(tab, 12);

return 0;
}