#include <cmath>
#include <iostream>
#include <limits>

using namespace std;


double simpsonIntegration(double (*f)(double), double from, double to, int n);


double logarithm(double x, int n);


int main(){
    printf("Ln(7)=%Lf\n", logarithm(7,16));
    printf("Ln(e)=%Lf\n", logarithm(2.718281828459,10));
    printf("Ln(0.5)=%Lf\n", logarithm(0.5,6));
    printf("Ln(-1)=%Lf\n", logarithm(-1,6));
    printf("Ln(0)=%Lf\n", logarithm(0,6));
    printf("Ln(-2)=%Lf\n", logarithm(-2,6));
    auto val = isnan( logarithm (-2, 2)) ? "Yes!" : "No!";
    cout << "Is Ln(-2) NaN? -> " << val;
    return 0;
}


double lognat(double x){return 1/x;}

double logarithm(double x, int n){
    if (x == 0){return numeric_limits<double>::infinity();}
    else if (x<0){return NAN;}
    double integral = simpsonIntegration(lognat, 1, x, n);
    return integral;
}


double simpsonIntegration (double (*f)(double), double from , double to , int n){
    double integration = 0.0,
           stepSize,
           k;
    if (f == nullptr){cout << "Brak zdefiniowanej funkcji\n"; return 0;}
    else if (n%2!=0){cout << "Algorytm dziala tylko dla parzystych wartoœci n\n"; return 0;}
    else{
    stepSize = (to - from)/n;
    integration = f(from)+f(to);
    for (int i = 1; i<=n-1; i++){
        k = from + i*stepSize;
        if(i%2==0){integration = integration + 2*(f(k));}
        else{integration = integration + 4*(f(k));}
    }
    integration = integration*stepSize/3;
    return integration;
    }
}
