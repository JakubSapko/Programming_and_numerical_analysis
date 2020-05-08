# include <iostream> // nie dawa spacji przed >
# include "exercise2.h"// zmien nazwe na odpowiednia

using namespace std ;

template < class T >
void print ( T * p ){
        cout << p->getM() << " " << p->getCharge() <<
         " " << p->getPDG() << " " << p->getSpin() <<
         " " << p->getRed() << " " << p->getGreen() <<
         " " << p->getBlue() << " " << p->getAntiRed() <<
         " " << p->getAntiGreen() << " " << p->getAntiBlue() << endl;
}


int main (){
// gauge vectors
    Vector gamma;
    gamma.setPDG(22);
    Vector Z(91.1876, 0, 23);
    print(&gamma);
    print(&Z);
// leptons
    Lepton e(0.00051 , -1 , 11 , 0.5);
    print(&e);
    Lepton mu(1.776 , -1 , 13 , 0.5);
    print(&mu);
    // quarks
    Hadron u(0.00022, 2./3, 2, 0.5);
    u.setGreen(true);
    print(&u);
    Hadron ab(4.18, 1./3, -5, 0.5);
    ab.setAntiRed(true);
    print(&ab);
    // Higgs
    Scalar h(125, 0, 25);
    print(&h);
    // proton
    Hadron p(0.938, 1, 2212, 0.5);
    print(&p);
    // gravitino !
    Lepton gr(3000, 0, 1000039, 3./2.);
    print(&gr);
    return 0;
}
