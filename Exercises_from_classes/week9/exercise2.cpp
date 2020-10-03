#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


double Diff(double (*f)(double), double x){
    double h = 0.1;
    return ((f(x+h)-f(x))/h);
}


template <class T>
bool newton(double &x, T f, double x0 , double eps , int n = 1000){
    int i = 0;
    double newx=0;
    while(abs(newx-x0)>eps||i<n){
        double newx=x0-(f(x)/Diff(f, x));
        x=newx;
        i++;
    }
    return x;
}





template <class T>
bool steffensen (double &x, T f, double x0 , double eps , int n = 1000){
    int i = 0;
}


//Functions//

double f1(double x) { return x * x; }
double f2(double x) { return x * x - 2.; }
double f3(double x) { return exp(x) + x - 1; }
/*
//Derivatives//

double df1(double x) { return 2*x; }
double df2(double x) { return 2*x; }
double df3(double x) { return exp(x)+1;}
*/

int main () {
    double x;
    cout <<"Newton :"<<endl;
    for (auto fx : {f1 , f2 , f3}) {
        for (auto eps : {0.1 , 0.01 , 0.001 , 0.0001 , 0.0000001}) {
            if (newton(x, fx , 1.4, eps )) {
                cout << setprecision (8) << "\teps = " << eps
                     << "\troot = " << x <<endl;
            } else {
                cout << "Unable to find root" <<endl;
                break;
            }
        }
        cout <<endl;
    }

    cout <<"Stefensen :"<<endl;
    for (auto fx : {f1 , f2 , f3}) {
        for (auto eps : {0.1 , 0.01 , 0.001 , 0.0001 , 0.0000001}) {
            if ( steffensen (x, fx , 1.4, eps )) {
                cout << setprecision (8) << "\teps = " << eps
                     << "\troot = " << x <<endl;
            } else {
                cout << "Unable to find root" <<endl;
                break;
            }
        }
        cout <<endl;
    }
return 0;
}
