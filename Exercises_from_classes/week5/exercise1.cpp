#include <iostream>
#include <stdlib.h>

using namespace std;
int placeholder = 0;

/*Trochê na si³e, ale dzia³a*/
void logis(long double a, long double x0, int n){
    if (placeholder == n){return;}
    else{
    long double x = a*x0*(1-x0);
    cout << placeholder+1 << "  " << x << endl;
    placeholder++;
    logis(a, x, n);
    } 
}

int main(int argc, char* argv[]){

    if (argc != 4){
        cout << "Nieprawid³owa liczba argumentów, podaj wszystkie 3 parametry(a, x0, n)";
    }
    else{
        long double a = atof(argv[1]);
        long double x0 = atof(argv[2]);
        int n = atoi(argv[3]);
        cout << "a = " << a << " x0 = " << x0 << " n = " << n << endl; 
        cout << "0 " << x0 << endl;
        logis(a, x0, n);
    }

return 0;
}
