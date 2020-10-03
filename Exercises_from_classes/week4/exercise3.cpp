#include <iostream>
#include <cmath>

using namespace std;

double lagint(double x, double xi[], double fx[], int n)
{
	double suma = 0;

	for (int i = 0; i < n; i++){
		double ilo = fx[i];
		for (int j = 0; j < n; j++){
			if (j != i)
			{ilo *= ((x - xi[j]) / (xi[i] - xi[j]));}
		}
		suma = suma + ilo;
	}
	return suma;
}


int main()
{
	int L = 100;
	int x_0 = 14;
	int k = 2;

	double xi[] = { 8, 8.12, 8.24, 8.36, 8.48, 8.60 };
	size_t sz = sizeof(xi) / sizeof(*xi);

	double fx[6];

	for (size_t i = 0; i < sz; i++){fx[i] = L / (1 + exp(-k * (xi[i] - x_0)));}
	cout << "x y inerp" << endl;
	for (size_t i = 0; i < sz; i++){cout << xi[i] << " " << fx[i] << " " << lagint(xi[i], xi, fx, sz) << endl;}
	return 0;
}
