#pragma once
/*TODO:
1. Particle (abstract):
    protected,
    gets/sets,
    constructor,
    parametrized constructor(mass, charge, PDG)
    parametrized constructor(mass, charge, PDG, red, green, blue, antiRed, antiBlue, antiGreen)
    virtual destructor
2. Boson (abstract):
    inherits from Particle
    protected:
        int spin;
    get/set,
    analogous constructors;
    default spin is 0.
3. Fermion (abstract):
    inherits from Particle, analogous to Boson, default spin is 1/2
4. Lepton (actual class):
    constructor,
    parametrized constructor(mass, charge, pdg, spin)
    default spin is 1/2, default colors are 0
5. Hadron (actual class):
    constructor,
    parametrized constructor(mass, charge, pdg, spin)
    parametrized constructor(mass, charge, pdg, spin, r, g, b, ar, ag, ab)
    default spin is 1/2, default colors are 0
6. Scalar (actual class):
    analogous constructors to Hadron's, const spin equal to 0
7. Vector (actual class):
    analogous to Scalar, spin equal to 1
-----------------------------------------*/

class Particle{
    protected:
        double m,
               eCharge;
        long int PDG;
        bool red,
             green,
             blue,
             antiRed,
             antiBlue,
             antiGreen;
    public:
        void setM(double m);
        void setCharge(double charge);
        void setPDG(long int pdg);
        void setRed(bool red);
        void setGreen(bool green);
        void setBlue(bool blue);
        void setAntiRed(bool antiRed);
        void setAntiGreen(bool antiGreen);
        void setAntiBlue(bool antiBlue);
        double getM();
        double getCharge();
        long int getPDG();
        bool getRed();
        bool getGreen();
        bool getBlue();
        bool getAntiRed();
        bool getAntiGreen();
        bool getAntiBlue();
        Particle();
        Particle(double mass, double charge, long int pdg);
        Particle(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab);
        virtual ~Particle() = 0;
};


class Boson : public Particle{
    protected:
        int spin;
    public:
        int getSpin();
        void setSpin(int spin);
        Boson();
        Boson(double mass, double charge, long int pdg, int sp);
        Boson(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab, int sp);
        virtual ~Boson() = 0;
};


class Fermion : public Particle{
    protected:
        int spin;
    public:
        int getSpin();
        void setSpin(int spin);
        Fermion();
        Fermion(double mass, double charge, long int pdg, int sp);
        Fermion(double mass, double charge, long int pdg, bool r, bool g, bool b, bool ar, bool ag, bool ab, int sp);
        virtual ~Fermion() = 0;
};


class Lepton : public Fermion{
    public:
        Lepton();
        Lepton(double mass, double charge, long int pdg, double sp);
};


class Hadron : public Fermion{
    public:
        Hadron();
        Hadron(double mass , double charge , long int pdg , double sp );
        Hadron(double mass , double charge , long int pdg , bool r , bool g , bool b , bool ar , bool ag , bool ab,  double sp  );
};


class Scalar : public Boson{
    public:
        Scalar();
        Scalar(double mass , double charge , long int pdg);
        Scalar(double mass , double charge , long int pdg , bool r , bool g , bool b , bool ar , bool ag , bool ab );

};



class Vector : public Boson{
    public:
        Vector();
        Vector(double mass , double charge , long int pdg);
        Vector(double mass , double charge , long int pdg , bool r , bool g , bool b , bool ar , bool ag , bool ab );

};
