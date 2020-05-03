#include <cmath >
#include <iomanip >
#include <iostream >


using namespace std;


template <class T>
bool bisection (double &x, T f, double from , double to , double eps ){
    if((f(from)*f(to)>=0) || (to<from) || (eps<0) || (eps>(to-from)) || (to-from)<0){
        cout << "Zle podane dane\n";
        return false;
    }
    else{
    double mid=from;

    while((to-from)>=eps){
        mid = (to+from)/2;
        if (f(mid) == 0.0){break;}
        else if(f(mid)*f(from)<0){to = mid;}
        else{from = mid;}
        //cout <<"mid " << mid << " f(mid) " <<  f(mid) << endl;
    }
    //cout << "mid " << mid;
    x = mid;
    return x;
    }
}


double f1(double x) { return x * x; }
double f2(double x) { return x * x - 2.; }
double f3(double x) { return exp(x) + x - 1; }


int main (){

    double x;
    for (auto fx : {f1 , f2 , f3}){
            for (auto eps : {0.1 , 0.01 , 0.001 , 0.0001 , 0.0000001}){
                if ( bisection (x, fx , -1, 6, eps )){
                    cout << setprecision (8) << "eps = " << eps
                                << "\t root = " << x << endl;
                }
                else{
                    cout << "Unable to find root" << endl;
                    break;
                }
            }
            cout << endl;
    }
return 0;
}
