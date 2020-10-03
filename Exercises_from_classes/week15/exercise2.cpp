#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <functional>
using namespace std;


template <typename T> int sgn(T val) 
{
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else 
		return 0;
}

template <class T>
double RungeKutta(T f, double x, double x0, double y0, double step)
{
	double h = sgn(x - x0) * abs(step);
	double k1,k2,k3,k4;
	double old_sgn = sgn(x-x0);
	while (sgn(x-x0)*old_sgn > 0)
	{
		k1 = f(x0, y0);
		k2 = f(x0+h/2., y0+(h/2.)*k1);
		k3 = f(x0+h/2., y0+(h/2.)*k2);
		k4 = f(x0+h, y0+h*k3);
		y0 +=1./6.*h*(k1 + 2*k2 + 2*k3 + k4);
		x0 += h;
	}
	return y0;
}


double eq(double x, double y)
{
	return y;
}

double foo(double x, double y)
{
	return x+y;
}

double poly(double x, double y)
{
	return 3 * x * x;
}

double bernoulli(double x, double y)
{
	if (x == 0)
		return NAN;
	else
		return x * y * y - y / x;
}

//jaki fajny szablon!
template <typename T>
using funcPointer = double (*)(T, double, double, double, double);

int main()
{
	vector<double> step = { 1., 0.25, 0.1, 0.05, 0.025, 0.0125, 0.0001 };

	cout <<"RungeKutta method:" << setprecision(6) << endl;
	cout << "y'=y and y(0)=1 -> y(3)=exp(3)=20,0855"
		<< endl;
	for (auto s : step)
	{
		double res = RungeKutta(eq, 3, 0, 1, s);
		cout << "h=" << s << " y=" << res
			<< " err=" << abs(res - exp(3)) << endl;
	}
	cout << endl;

	cout << "y'=3x^2 and y(1)=1 -> y(-3)=(-3)^3=-27"
		<< endl;
	for (auto s : step)
	{
		double res = RungeKutta(poly, -3, 1, 1, s);
		cout << "h=" << s << " y=" << res
			<< " err=" << abs(res + 27) << endl;
	}
	cout << endl;

	cout << "y'=xy^2-y/x and y(1)=-1 -> y(3)=-1/[(-3)^2]=-0.1111"
		<< endl;
	for (auto s : step)
	{
		double res = RungeKutta(bernoulli, 3, 1, -1, 1 * s);
		cout << "h=" << s << " y=" <<
			res << " err=" << abs(res + 0.111) << endl;
	}
	cout << endl;

	cout << "y'=x+y and y(0)=0 -> y(-1)=1/e=0.3678"
		<< endl;
	for (auto s : step)
	{
		double res = RungeKutta(foo, -1, 0, 0, s);
		cout << "h=" << s << " y=" << res
			<< " err=" << abs(res-0.3679) << endl;
	}
	cout << endl;
	
}