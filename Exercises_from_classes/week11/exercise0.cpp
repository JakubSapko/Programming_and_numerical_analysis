#include <iostream>
#include <cmath>


class Wektor{
    private:
        double x;
        double y;
        double z;
    public:
        void setX(double a){x = a;}
        void setY(double a){y = a;}
        void setZ(double a){z = a;}
        double getX() const { return x;}
        double getY() const { return y;}
        double getZ() const { return z;}
        Wektor ( const double a =0. , const double b =0. , const double c =0.)
        : x ( a ) , y ( b ) , z ( c ){}
        double getModule (){ return sqrt ( x * x + y * y + z * z );}
        friend std :: ostream & operator <<( std :: ostream & out , const Wektor & c );
        Wektor operator+(const Wektor& w) const {
            return Wektor(x+w.getX(), y+w.getY(), z+w.getZ());
        };
        Wektor operator-(const Wektor& w) const {
            return Wektor(x-w.getX(), y-w.getY(), z-w.getZ());
        };
        double operator*(const Wektor& w) const {
            return x*w.getX()+y*w.getY()+z*w.getZ();
        };
        bool operator==(const Wektor& w) const {
            return (x==w.getX() && y==w.getY() && z==w.getZ());
        };
        Wektor operator-() const {
            return Wektor(-x, -y, -z);
        };
        };

        std :: ostream & operator <<( std :: ostream & os , const Wektor & w )
        {
        os << "(" << w . x << "," << w . y << "," << w . z << ")";
        return os;
        };


int main (){

    Wektor w(5. , -1. , 3.);
    Wektor v;
    v.setX(1.);
    v.setY(2.);
    v.setZ( -3.);

    std :: cout << w << std :: endl << v << std :: endl;
    std :: cout << -w << std :: endl;
    std :: cout << w + v << std :: endl;
    std :: cout << w - v << std :: endl;
    std :: cout << w * v << std :: endl;
    std :: cout << ( w == v ) << std :: endl;
    std :: cout << ( Wektor (5. , -1. , 3.)== w ) << std :: endl;
    return 0;
}
