#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char* argv[]){
	if (argc != 4){cout << "Niepoprawna ilosc argumentow programu. Program przyjmuje 3 argumenty podczas uruchomienia (mi, sigma, N)";}
	else if(atoi(argv[3]) <= 0){cout <<"Liczba punktow do wygenerowania musi byc wieksza od zera!";}
	else{
		double mi = atof(argv[1]);
		double sigma = atof(argv[2]);
		int N = atoi(argv[3]);
		int mniejszy = 0;
		int wiekszy = 0;
		unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
		default_random_engine e (seed);
		normal_distribution<double> dist(mi, sigma);
		for (int i = 0; i<N; i++){
			double x = dist(e);
			if ((x>-sigma) && (x<sigma)){mniejszy++;}
			if ((x>-2*sigma) && (x<2*sigma)){wiekszy++;}
		}
	double calka1 = (static_cast<double>(mniejszy)/static_cast<double>(N));
	double calka2 = (static_cast<double>(wiekszy)/static_cast<double>(N));
	cout << "Calka na przedziale (" << sigma-mi << ", " << sigma+mi << ") = " << calka1 << endl;
	cout << "Calka na przedziale (" << sigma-2*mi << ", " << sigma+2*mi << ") = " << calka2 << endl;
	}
return 0;
}
