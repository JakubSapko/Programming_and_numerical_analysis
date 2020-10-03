#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
	
	if (argc!=2){cout << "Podano zla liczbe argumentow programu. Program przyjmuje jedna wartosc poczatkowa N.";}
	else if (atoi(argv[1]) < 0 ){cout << "Podany argument jest nieprawidlowy. Oczekiwana wartosc argumentu powinna byc liczba dodatnia.";}
	else {
		unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
		default_random_engine e (seed);
		uniform_real_distribution<> dist(0,1);
		int N = atoi(argv[1]);
		int inside = 0;
		for (int i = 0; i<N; i++){
			double x = dist(e);
			double y = dist(e);
			double distance = sqrt(x*x+y*y);
			if (distance <= 1){ inside++;}
		}
		cout << "W polu: " << inside << endl;
		cout << "Wszystkich: " << N << endl;
		double appPi = (static_cast<double>(inside)/static_cast<double>(N))*4;
		cout << "Approksymowana wartosc pi wyniosla: " << appPi;
	}

return 0;
}
