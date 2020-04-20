#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double gaussQuad(double from, double to, vector<double> w, vector<double> x, double (*f)(double));

double f1(double x){ return 2*x*x+x+2;}

double f2(double x){ return cos(x)*x;}

double poly(double x){
    double sum = 0;
    for (int i=1; i!= 9; ++i){
        sum  += (i+1)*pow(x, i);
    }
    return sum;
}

vector<double> w{};
int main() {
	auto xexp = [](double i) { return i * exp(i); };
	// n=3
	vector<double> w{ 0.555555555555556, 0.888888888888889, 0.555555555555556 };
	vector<double> x{ -0.774596669241483, 0, 0.774596669241483 };
	cout << "n=" << x.size() << endl;
	cout << "\tf1 (should be 22.9973): " << gaussQuad(-2.2, 2.2, w, x, f1) << endl;
	cout << "\tf2 (should be 0): " << gaussQuad(0, 2 * M_PI, w, x, f2) << endl;
	cout << "\tpoly[8] (should be 8): " << gaussQuad(0, 1, w, x, poly) << endl;
	cout << "\tx*exp(x) (should be 1): " << gaussQuad(0, 1, w, x, xexp) << endl;
	// n=5;
	w = { 0.236926885056189, 0.478628670499366, 0.568888888888889, 0.478628670499366, 0.236926885056189 };
	x = { -0.906179845938664, -0.538469310105683, 0, 0.538469310105683, 0.906179845938664 };
	cout << "n=" << x.size() << endl;
	cout << "\tf2 (should be 0): " << gaussQuad(0, 2 * M_PI, w, x, f2) << endl;
	cout << "\tpoly[8] (should be 8): " << gaussQuad(0, 1, w, x, poly) << endl;
	cout << "\tx*exp(x) (should be 1): " << gaussQuad(0, 1, w, x, xexp) << endl;
	return 0;
}

double gaussQuad(double from, double to, vector<double> w, vector<double> x, double (*f)(double)){
    int s = x.size();
    double suma = 0;
    if (s<1){printf("Wektor pusty"); return -1;}
    for (int i = 0; i<s; i++){
        suma += (to - from)/2 * w.at(i) * f((to - from) /2 *x.at(i) + (from+to)/2);
    }
    return suma;
}
