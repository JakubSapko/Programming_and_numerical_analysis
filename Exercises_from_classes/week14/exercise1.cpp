#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Owoc
{
public:
	virtual void powitanie()
	{cout << "Jestem sobie pysznym owocem!" << endl;}
	virtual ~Owoc() = 0;
};

Owoc::~Owoc() {}

class Jablko : public Owoc
{
public:
	virtual void powitanie()
	{cout << "Jestem sobie pysznym jablkiem!" << endl;}
};

class Gruszka : public Owoc
{
public:
	virtual void powitanie()
	{cout << "Jestem sobie pyszna gruszka!" << endl;}
};

class Banan : public Owoc
{
public:
	virtual void powitanie()
	{cout << "Jestem sobie pysznym bananem!" << endl;}
};


class Fabryka
{
public:
	static Owoc* uprawiajOwoc(string rodzaj)
	{
		if(rodzaj == "jablko")
			return new Jablko;
		else if(rodzaj == "gruszka")
			return new Gruszka;
		else if(rodzaj == "banan")
			return new Banan;
		else
			return nullptr;
	}
};

int main()
{
	//wektor wskaznikow na klase abstrakcyjna?
	vector<Owoc*> v;
	// v.push_back(new Jablko);
	// v.push_back(new Gruszka);
	// v.push_back(new Banan);
	v.push_back(Fabryka::uprawiajOwoc("jablko"));
	v.push_back(Fabryka::uprawiajOwoc("gruszka"));
	v.push_back(Fabryka::uprawiajOwoc("banan"));
	cout << "Podaj nazwe..." << endl;
	string nazwa;
	cin >> nazwa;
	v.push_back(Fabryka::uprawiajOwoc(nazwa));

	for(auto owoc : v)
	{
		if(owoc)
			owoc->powitanie();
	}
	//dostep do metody w klasie abstrakcyjnej
	v[0]->Owoc::powitanie();
	//zawsze pamietamy o zwolnieniu pamieci
	for(int ii=v.size(); ii>0; ii--)
	{
		if(v[ii])
			delete v[ii];
	}

	return 0;
}