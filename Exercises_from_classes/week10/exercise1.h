#pragma once
#include <cmath>
#define _USE_MATH_DEFINES


class TLorentzVector{
    private:
        double x, y, z, t;
    public:
        TLorentzVector();
        TLorentzVector(double x, double y, double z, double t);
        double getX(){return this->x;}
        double getY(){return this->y;}
        double getZ(){return this->z;}
        double getT(){return this->t;}
        void setX(double x){this->x=x;}
        void setY(double y){this->y=y;}
        void setZ(double z){this->z=z;}
        void setT(double t){this->t=t;}
        double Mag2();
        double Mag();
        double Phi();
        double Theta();
};

