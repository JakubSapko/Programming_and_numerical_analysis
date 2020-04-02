#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES


using namespace std;


double sin2(double x)
{
    return sin(x)*sin(x);
}


double calka(double x1, double x2, double (*func) (double), int w){
    if (func == nullptr){cout << "Nie podano zadnej funkcji" << endl; exit(1);}
    double sr = (x2-x1)/static_cast<double>(w);
    double sum = 0;
    for (int i = 0; i<w; i++){sum += sr*func(x1+i*sr+sr/2);}
    return sum;
}

int main(){

cout << "Calka z sin(x) od 0 do pi przy 10 podzialach: "
<< calka(0, M_PI, sin, 10) << endl;
cout << "Calka z sin(x) od 0 do pi przy 100 podzialach: "
<< calka(0, M_PI, sin, 100) << endl;
cout << "Calka z sin(x) od 0 do pi przy 1000 podzialow: "
<< calka(0, M_PI, sin, 1000) << endl;
cout << "Calka z cos(x) od 0 do pi przy 1000000 podzialow: "
<< calka(0, M_PI, cos, 1000000) << endl;
cout << "Calka z sin^2(x) od 0 do 2pi przy 1000 podzialow: "
<< calka(0, 2*M_PI, sin2, 1000) << endl;
cout << "Calka z sin^2(x) od 2pi do 0 przy 1000 podzialow: "
<< calka(2*M_PI, 0, sin2, 1000) << endl;
cout << "Calka z sin^2(x) od 0 do 0 przy 1000 podzialow: "
<< calka(0, 0, sin2, 1000) << endl;
// cout << "Calka z sin^2(x) od 0 do pi przy 0 podzialow: "
//<< calka(0, M_PI, sin2, 0) << endl;
cout << "Proba uzycia nullptr: " <<
calka(0, M_PI, nullptr, 10) << endl;

return 0;
}
