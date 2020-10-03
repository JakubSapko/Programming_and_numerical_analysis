#include <iostream>
#include <cmath>


using namespace std;


double sin2(double x)
{
return sin(x)*sin(x);
}

void calka(double x1, double x2, double (*ftab[])(double), int s, int n);


int main()
{
double (*ftab[])(double) = {sin, cos, nullptr, nullptr, sin2};
calka(0.0, M_PI, ftab, 5, 10);
cout << endl;
calka(0.0, -M_PI, ftab, 5, 1000);
cout << endl;
calka(5.0, 5.0, ftab, 5, 1000);
cout << endl;
calka(0.0, M_PI, ftab, 5, -6);
cout << endl;

return 0;
}

void calka(double x1, double x2, double (*ftab[])(double), int s, int n){
    if(n<=0){printf("Liczba przedzialow musi byc wieksza od zera"); exit(0);}
    for(int i = 0; i<s; i++){
     if (ftab[i] == nullptr){printf("Brak funkcji. \n"); continue;}
     else{
        double sr = (x2-x1)/static_cast <double> (n);
        double suma = 0;
        for (int k = 0; k < n; k++){
            suma += sr*(ftab[i](x1+k*sr)+ftab[i](x1+(k+1)*sr))/2;
        }
        printf("Calka z funkcji nr %d w zakresie od %f do %f wyniosla %E. \n", i, x1, x2, suma);
     }
    }
}
