#include <iostream>

class Box
{
public:
	static int counter;
	double a;
	double b;
	double c;
	Box(double x=0, double y=0, double z=0)
	: a(x), b(y), c(z){counter++;}
	double volume(){return a*b*c;}
	static int getCounter(){return counter;}
};

int Box::counter = 0;

int main()
{
	Box(5.2, 1., 9.);
	Box(11, 4.35, 5.5);
	Box(8., 2., 1.);
	Box(4., 4., 4.);
	Box(1., 2., 3.);

	std::cout << "No of boxes: "
	<< Box::getCounter()
	<< std::endl;
	return 0;
}