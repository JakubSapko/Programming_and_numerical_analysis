#include "js1.h"


TLorentzVector::TLorentzVector(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->t = 0;
}

TLorentzVector::TLorentzVector(double x, double y, double z, double t){
    this->x = x;
    this->y = y;
    this->z = z;
    this->t = t;
}

double TLorentzVector::Mag2(){
    double s = pow(t, 2)-pow(x, 2)-pow(y, 2)-pow(z, 2);
    return s;
}

double TLorentzVector::Mag(){
    if (sqrt(Mag2())>=0){
        return sqrt(Mag2());
    }
    else{
        return -1*sqrt(-1*Mag2());
    }
}

double TLorentzVector::Phi(){
    return atan2(y, x);
}

double TLorentzVector::Theta(){
    double w = sqrt(x*x + y*y);
    return atan2(w, z);
}
