#include "exercise2.h"

//---Particle methods---//
Particle::Particle(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
}


Particle::Particle(double mass, double charge, long int pdg){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
}


Particle::Particle(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
}

Particle::~Particle(){}

//---Sets---//

void Particle::setM(double m){
    this->m = m;
}

void Particle::setCharge(double charge){
    this->eCharge = charge;
}

void Particle::setPDG(long int pdg){
    this->PDG = pdg;
}

void Particle::setRed(bool red){
    this->red = red;
}

void Particle::setGreen(bool green){
    this->green = green;
}

void Particle::setBlue(bool blue){
    this->blue = blue;
}

void Particle::setAntiRed(bool antiRed){
    this->antiRed = antiRed;
}

void Particle::setAntiGreen(bool antiGreen){
    this->antiGreen = antiGreen;
}

void Particle::setAntiBlue(bool antiBlue){
    this->antiBlue = antiBlue;
}

//---Gets---//


double Particle::getM(){
    return this->m;
}

double Particle::getCharge(){
    return this->eCharge;
}

long int Particle::getPDG(){
    return this->PDG;
}

bool Particle::getRed(){
    return this->red;
}

bool Particle::getGreen(){
    return this->green;
}

bool Particle::getBlue(){
    return this->blue;
}

bool Particle::getAntiRed(){
    return this->antiRed;
}

bool Particle::getAntiGreen(){
    return this->antiGreen;
}

bool Particle::getAntiBlue(){
    return this->antiBlue;
}


//---End of Particle methods---//
//---Boson methods---//


Boson::Boson(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0;
}


Boson::Boson(double mass, double charge, long int pdg, int sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = sp;
}


Boson::Boson(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab, int sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
    this->spin = sp;
}

Boson::~Boson(){}



int Boson::getSpin(){
    return this->spin;
}


void Boson::setSpin(int spin){
    this->spin = spin;
}
//---End of Boson methods---//
//---Fermion methods---//


Fermion::Fermion(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0.5;
}


Fermion::Fermion(double mass, double charge, long int pdg, int sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = sp;
}


Fermion::Fermion(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab, int sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
    this->spin = sp;
}


Fermion::~Fermion(){}


int Fermion::getSpin(){
    return this->spin;
}


void Fermion::setSpin(int spin){
    this->spin = spin;
}
//---End of Fermion methods---//
//---Lepton methods---//


Lepton::Lepton(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0.5;
}


Lepton::Lepton(double mass, double charge, long int pdg, double sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = sp;
}

//---End of Lepton methods---//
//---Hadron methods---//


Hadron::Hadron(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0.5;
}

Hadron::Hadron(double mass, double charge, long int pdg, double sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = sp;
}


Hadron::Hadron(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab, double sp){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
    this->spin = sp;
}

//---End of Hadron methods---//
//---Scalar methods---//

Scalar::Scalar(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0;
}

Scalar::Scalar(double mass, double charge, long int pdg){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 0;
}


Scalar::Scalar(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
    this->spin = 0;
}
//---End of Scalar methods---//
//---Vector methods---//

Vector::Vector(){
    this->m = 0;
    this->eCharge = 0;
    this->PDG = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 1;
}

Vector::Vector(double mass, double charge, long int pdg){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->antiRed = 0;
    this->antiGreen = 0;
    this->antiBlue = 0;
    this->spin = 1;
}


Vector::Vector(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab){
    this->m = mass;
    this->eCharge = charge;
    this->PDG = pdg;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->antiRed = ar;
    this->antiGreen = ag;
    this->antiBlue = ab;
    this->spin = 1;
}


//---End of Vector methods---//
