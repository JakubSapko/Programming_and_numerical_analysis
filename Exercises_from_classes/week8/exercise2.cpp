#include <iostream>
#include <cmath>


using namespace std;


double forwardDiff(double (*f)(double), double x, double h);
double backwardDiff(double (*f)(double), double x, double h);
double centralDiff(double (*f)(double), double x, double h);
double richardsonDiff(double (*f)(double), double x, double h);
double centralSecondDiff(double (*f)(double), double x, double h);

double poly(double x){
    double sum = 0;
    for (int i=1; i!=9; ++i){
        sum+=(i+1)*pow(x, i);
    }
    return sum;
}

int main(){
    auto h = {0.01, 0.00001};
    auto v = {poly, cos};
    for (auto hi: h){
        cout << "h=" << hi << endl;
        for (auto f: v){
            cout << forwardDiff(f, 0, hi) << endl;
            cout << backwardDiff(f, 0, hi) << endl;
            cout << centralDiff(f, 0, hi) << endl;
            cout << richardsonDiff(f, 0, hi) << endl;
            cout << centralSecondDiff(f, 0, hi) << endl;
            cout << endl;
        }
    }
    return 0;
}

double forwardDiff(double (*f)(double), double x, double h){
    return ((f(x+h)-f(x))/h);
}

double backwardDiff(double (*f)(double), double x, double h){
    return ((f(x)-f(x-h))/h);
}

double centralDiff(double (*f)(double), double x, double h){
    return ((f(x+h)-f(x-h))/(2*h));
}

double richardsonDiff(double (*f)(double), double x, double h){
    return ((-f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h))/(12*h));
}

double centralSecondDiff(double (*f)(double), double x, double h){
    return ((f(x+h)-2*f(x)+f(x-h))/(h*h));
}
