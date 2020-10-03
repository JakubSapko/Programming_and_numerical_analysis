#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//tu napisz klase Complex

class Complex{
    public:
        double real;
        double imaginary;
        double magnitude;
        double phase;
        Complex(){
            real = 0;
            imaginary = 0;
            magnitude = 0;
            phase = 0;
        }
        Complex(double real, double imaginary){
            this->real = real;
            this->imaginary = imaginary;
            this->magnitude = sqrt(pow(real, 2.0)+pow(imaginary, 2.0));
            this->phase = atan2(imaginary, real);
        }
        void zwrocReal();
        void zwrocIm();
        void zwrocModul();
        void zwrocPhase();
        void printAlg();
        void printExp();
        Complex dodajZespolone(Complex a);
        Complex odejmijZespolone(Complex a);
        Complex pomnozZespolone(Complex a);
        Complex podzielZespolone(Complex a);
};


void Complex::zwrocReal(){
    cout << real << endl;
}


void Complex::zwrocIm(){
    cout << imaginary << endl;
}

void Complex::zwrocModul(){
    cout << magnitude << endl;
}

void Complex::zwrocPhase(){
    cout << phase << endl;
}

void Complex::printAlg(){
    string znak;
    if (real == 0){cout << imaginary << "*i" << endl; return;}
    else{
    if (imaginary>0){znak = "+";}
    else if(imaginary<0){znak = "-";}
    else{cout << real << endl; return;}
    cout << real << "" << znak << "" << abs(imaginary) << "*i"<<endl;}
}


void Complex::printExp(){

    if (phase<0){cout << magnitude << "*exp(-i*" << abs(phase) << ")" << endl; return; }
    else{
    cout << magnitude << "*exp(i*" << phase << ")" << endl;}
}


Complex Complex::dodajZespolone(Complex a){
    Complex add;
    add.real = real + a.real;
    add.imaginary = imaginary + a.imaginary;
    return add;
}


Complex Complex::odejmijZespolone(Complex a){
    Complex sub;
    sub.real = real - a.real;
    sub.imaginary = imaginary - a.imaginary;
    return sub;
}


Complex Complex::pomnozZespolone(Complex a){
    Complex Mult;
    Mult.real = real*a.real - imaginary*a.imaginary;
    Mult.imaginary = real*a.imaginary - a.real*imaginary;
    return Mult;
 }

Complex Complex::podzielZespolone(Complex a){
    Complex Div;
    Div.real = (real*a.real + imaginary*a.imaginary)/(a.real*a.real + a.imaginary*a.imaginary);
    Div.imaginary = (imaginary*a.real + real*a.imaginary)/(a.real*a.real + a.imaginary*a.imaginary);
    return Div;
 }

int main()
{
//tu stworz wektor i wypelnij

vector<Complex> v{{sqrt(3)/2, 0.5}, {-0.5, sqrt(3)/2}, {-1, 0}, {0, -1}};


for(auto iter = v.begin(); iter!=v.end(); iter++)
{
iter -> printAlg();
iter -> printExp();
std::cout << std::endl;
}

return 0;

/*
Complex a;
Complex b(2, 3);
Complex c(2, -4);

a.zwrocReal();
b.zwrocReal();
c.zwrocReal();
c.zwrocIm();
a.printAlg();
b.printAlg();
c.printAlg();
a.zwrocModul();
b.zwrocModul();
c.zwrocModul();
a.zwrocPhase();
b.zwrocPhase();
c.zwrocPhase();
a.printExp();
b.printExp();
c.printExp();
Complex d = c.dodajZespolone(b);
d.printAlg();
Complex w = d.odejmijZespolone(c);
w.printAlg();
*/
return 0;
}
