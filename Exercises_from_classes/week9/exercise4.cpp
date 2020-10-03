#include <iostream> //nie ma spacji przed >
using namespace std;

class Kontener
{
	public:
		unsigned no;
		Kontener* nast;
		Kontener()
		{
			this->no = 0;
			this->nast = nullptr;
		};
		Kontener(unsigned no)
		{
			this->no = no; //ta sama nazwa rozne rzeczy!
			this->nast = nullptr;
		};
};

void dodajEl(Kontener* biezacy, Kontener* nowy)
{
	// dodaj element "nowy" do listy za "biezacy" 
	if(biezacy && nowy)
	{
		if(biezacy->nast)
		{
			Kontener* wsk = biezacy->nast;
			biezacy->nast = nowy;
			nowy->nast = wsk;
		}
		else
		{
			biezacy->nast = nowy;
		}
	}
	else
	{
		cout << "[ERROR] Nullptr!" << endl;
	}
}

void wypiszListe(Kontener* pocz)
{
	if(!pocz)
	{
		cout << "[ERROR] Nullptr!" << endl;
	}
	else
	{
		do
		{
			cout << pocz->no << " ";
			pocz = pocz->nast;
		}
		while(pocz);
	}
	cout << endl;
}

Kontener* usunElPoID(Kontener* pocz, unsigned no)
{
	// usun elementy, z danym no
	if(pocz)
	{
		while(pocz && pocz->no == no)
		{
			Kontener* wsk = pocz;
			pocz = wsk -> nast;
			delete wsk;
		}
		
		Kontener* biezacy = pocz;
		Kontener* poprzedni = nullptr;
		while(biezacy)
		{
			Kontener* kolejny = biezacy->nast;
			if(biezacy->no == no)
			{
				if(poprzedni)
					poprzedni -> nast = kolejny;
				delete biezacy;
			}
			else
				poprzedni = biezacy;
			biezacy = kolejny;
		};

		return pocz;
		
	}
	else
	{
		cout << "Pusty poczatek!" << endl;
		return pocz;
	}
}
int main()
{
	//pierwszy element listy
	Kontener* pocz = new Kontener();
	Kontener* biezacy = pocz;
	Kontener* dzies = nullptr;

	// dodaj elementy do listy
	for(unsigned ii=1; ii<33; ii++)
	{
		Kontener* nowy = new Kontener(ii%10);
		dodajEl(biezacy, nowy);
		biezacy = nowy;
		if(ii==10)
			dzies = biezacy;
	}
	//wypisz cala liste
	wypiszListe(pocz);

	//dodaj po elemencie ii=10
	dodajEl(dzies, new Kontener(100));
	wypiszListe(pocz);
	//wypisz od elementu ii=10
	wypiszListe(dzies);

	//usun wszystkie elementy z no=2 po elemencie ii=10
	usunElPoID(dzies, 2);
	wypiszListe(pocz);

	//dodaje element z no=0 po pierwszym
	dodajEl(pocz, new Kontener(0));
	wypiszListe(pocz);
	for(unsigned ii=0; ii<=11; ii++)
	{
		//usun wszystkie elementy z no=ii 
		pocz = usunElPoID(pocz, ii);
		wypiszListe(pocz);
	}
	pocz = usunElPoID(pocz, 100);
	wypiszListe(pocz);
	return 0;
}