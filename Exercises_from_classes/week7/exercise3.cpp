#include <iostream>
#include <vector>

using namespace std;

void wypiszMacierz(vector<double*>* M)
{
	if(M)
	{
		for(auto it = M->begin(); it != M->end(); it++)
		{
			for(int ii=0; ii<M->size(); ii++)
			{
				cout << (*it)[ii] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "Pusta!" << endl;
	
}

vector<double*>* tworzMacierz(unsigned n)
{
	if(n > 0)
	{
		vector<double*>* v = new vector<double*>;
		for(unsigned ii=0; ii<n; ii++)
		{
			double* tab = new double[n];
			for(unsigned jj=0; jj<n; jj++)
			{
				tab[jj] = (ii==jj) ? n-ii : 0.0;
			}
			v->push_back(tab);
		}
		return v;
	}
	else
		return nullptr;
}

void usunMacierz(vector<double*>* M)
{
	if(M)
	{
		for(auto iter = M->begin(); iter != M->end(); iter++)
		{
			delete[] *iter;
		}
		M->erase(M->begin(), M->end());
		delete M;
	}
	else
		cout << "Nie ma co usuwać!" << endl;	
}

int main()
{
	unsigned n = 5;
	cout << "Tworze macierz..." << endl;
	auto M = tworzMacierz(n);
	cout << "Oto ona:" << endl;
	wypiszMacierz(M);
	cout << "Usuwam macierz..." << endl;
	usunMacierz(M);
	cout << "Usunięto!" << endl;

	cout << "Tworze macierz..." << endl;
	auto N = tworzMacierz(0);
	cout << "Oto ona:" << endl;
	wypiszMacierz(N);
	cout << "Usuwam macierz..." << endl;
	usunMacierz(N);
}