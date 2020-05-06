#include <iostream>
#include "js1.h"
using namespace std;

int main (){
    TLorentzVector v (5 , -2 , -1 , 3);
    cout << v . getX () << " " <<
            v . getY () << " " << v . getZ () << " "
         << v . getT () <<endl ;
    cout << v . Mag2 () << " " << v . Mag ()
         <<endl ;

double pi = 3.14159265359;

v . setX (2* cos ( pi /3)* sin ( pi /2));

v . setY (2* sin ( pi /3)* sin ( pi /2));

v . setZ (2* cos ( pi /2));

v . setT (0);

    cout << v . getX () << " " <<
            v . getY () << " " << v . getZ () << " "
         << v . getT () <<endl ;
    cout << "phi=" << v . Phi () <<
            " theta =" << v . Theta () <<endl ;
return 0;
}
