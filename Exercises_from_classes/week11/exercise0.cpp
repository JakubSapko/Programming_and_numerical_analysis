#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;


template <class T >
bool secant ( double &x , T f , double x0 , double x1 , double eps , int n = 1000){
    x = x0;
    double c, xp, xInter, xm;
    if(eps<=0){cout << "Wrong epsilon" << endl; return false;}
    if(n<=0){cout << "Wrong n" << endl; return false;}
    if(f==nullptr){cout <<"No function" << endl; return false;}
    else{
    do{
            //intermediate value
            xInter = (x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
            //xInter = x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
            c = f(xInter)*f(x0);
            x0 = x1;
            x1 = xInter;
            n--;
            if (c==0.0){
                break;
            }
            if (n==0){
                cout << "Number of iterations exceeded.";
                return false;
            }
            xm = (x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
        } while(fabs(xm - xInter)>= eps);}
    x = xInter;
    return true;
}


template <class T >
bool secantExtr ( double &x , T f , double x0 , double x1 , double eps , int n = 1000){
    x = x0;
    double c, xp, xInter, xm;
    double h = 1e-7;
    if(eps<=0){cout << "Wrong epsilon" << endl; return false;}
    if(n<=0){cout << "Wrong n" << endl; return false;}
    if(f==nullptr){cout <<"No function" << endl; return false;}
    else{
    do{
            //(f(x+h)-f(x))/h
            //intermediate value
            xInter = (x0*((f(x1+h)-f(x1))/h)-x1*(f(x0+h)-f(x0))/h)/(((f(x1+h)-f(x1))/h)-(f(x0+h)-f(x0))/h);
            //xInter = x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
            c = f(xInter)*f(x0);
            //c = (f(xInter+h)-f(xInter))/h*(f(x0+h)-f(x0))/h;
            x0 = x1;
            x1 = xInter;
            n--;
            if (c==0.0){
                break;
            }
            if (n==0){
                cout << "Number of iterations exceeded.";
                return false;
            }
            xm = (x0*((f(x1+h)-f(x1))/h)-x1*(f(x0+h)-f(x0))/h)/(((f(x1+h)-f(x1))/h)-(f(x0+h)-f(x0))/h);
        } while(fabs(xm - xInter)>= eps);}
    x = xInter;
    return true;
}

double f1 ( double x ) { return x * x ; }
double f2 ( double x ) { return x * x - 2.; }
double f3 ( double x ) { return (exp( x ) + x - 1); }
double f4 ( double x ) { return (log( x ) - x +1.0);}
double f5 ( double x ) { return sin( x +0.5);}
int main () {
    double x;
    for ( auto fx : { f1 , f2 , f3 , f4 , f5 }) {
        for ( auto eps : {0.1 , 0.01 , 0.001 , 0.0001 , 0.0000001}) {
            if ( secant (x , fx , 0.1 , 3 , eps )) {
                cout << setprecision (8) << "eps = " << eps
                << "\t root = " << x << endl;
            } else {
                cout << " Unable to find root " <<endl;
            }
        }

        cout << endl ;
    }
    cout << "Extremal points :" << endl ;
    for ( auto fx : { f1 , f2 , f4 , f5 }) {
        for ( auto eps : {0.1 , 0.01 , 0.001 , 0.0001 , 0.0000001}) {
            if ( secantExtr (x , fx , 0.3 , 2 , eps )) {
                cout <<setprecision (8) << "eps = " << eps
                     << "\t point = " << x <<endl ;
            } else {
                cout << " Unable to find extremum " << endl ;
                }
            }
            cout <<endl ;
    }
    return 0;
}
