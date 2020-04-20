#include <iostream> // nie wolno spacji przed >
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES
/*
const std :: vector <double > * const oznacza staly wskaznik
(nie mozna zmienic na co wskazuje ) na stala
(nie mozna zmienic wartosci elementu wskazywanego )
*/
using namespace std;

double linear (const vector<double >* const px , const vector<double >* const py , const double x ){
    int s = px -> size();
    int w1 = -1,
        w2 = -1;
    double pmi, pma;
    //1.Szukanie bliskich
    for (int i = 0; i < s; i++){
        double x_i = px -> at(i);
        if (x == x_i){return py->at(i);}
        else if (x > x_i){
            if (w1 == -1){pmi = abs(x-x_i); w1 = i;}
            else if (abs(x_i - x) < pmi){pmi = abs(x_i-x); w1 = i;}
        }
        else if (x_i > x){
            if ( w2==-1){pma = abs(x-x_i); w2=i;}
            else if (pma > abs(x-x_i)){pma = x_i; w2 = i;}
        }
    }
    //2. Interpolacja funkcji prost¹
    //Wspó³czynniki
    double x1 = px -> at(w1),
           y1 = py -> at(w1),
           x2 = px -> at(w2),
           y2 = py -> at(w2),
           a = (y2-y1)/(x2-x1),
           b = (y1) - a*(x1);
    //Funkcja zwraca ostateczn¹ wartoœæ
    return a*x+b;
}

int main (){

vector <double > px {2 , -1 , 0 , 3};
vector <double > py {7 , 1 , 1 , 25};
vector <double > x {0 , -0.5 , 1 , 2.2};
for ( auto i : x )
{
cout << "p(" << i << ") = "

<< linear (& px , & py , i ) << endl ;

}

}
