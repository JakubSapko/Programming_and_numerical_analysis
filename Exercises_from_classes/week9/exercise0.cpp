#include <cmath>
#include <iostream>


using namespace std;


double simpsonIntegration (double (*f)(double), double from , double to , int n);


double square(double x) { return x * x; };


double xexp(double x) { return x * exp(x); };


double poly(double x){
    double sum = 0;
    for (int i = 1; i != 9; ++i){
        sum += (i + 1) * pow(x, i);
        }

return sum;
}


int main (){
    cout << simpsonIntegration (square , -1, 1, 6) <<endl;
    cout << simpsonIntegration (xexp , 0, 1, 6) <<endl;
    cout << simpsonIntegration (poly , 0, 1, 6) <<endl;
    cout << simpsonIntegration (poly , 0, 1, 100) <<endl;
    cout << simpsonIntegration (nullptr, 0, 1, 100) << endl;
    cout << simpsonIntegration (square, -1, 1, 11);
return 0;
}

double simpsonIntegration (double (*f)(double), double from , double to , int n){
    double integration = 0.0,
           stepSize,
           k;
    if (f == nullptr){cout << "Brak zdefiniowanej funkcji\n"; return 0;}
    else if (n%2!=0){cout << "Algorytm dziala tylko dla parzystych wartoœci n\n"; return 0;}
    else{
    stepSize = abs((from - to))/n;
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
