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
double AdamsBashford(T f, double x, double x0, double y0, double step)
{
	double s = sgn(x - x0) * abs(step);
	double x1 = x0 + s;
	double y1 = y0 += s*f(x0,y0);
	double old_sgn = sgn(x-x0);
	while (sgn(x-x0)*old_sgn > 0)
	{
		double val = y1 + s/2.*(3*f(x1,y1)-f(x0,y0));
		x0 = x1;
		y0 = y1;
		y1 = val;
		x1 += s;
	}

	return y1;
}


double eq(double x, double y)
{
	return y;
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
	vector<double> step = { 1., 0.25, 0.1, 0.05, 0.025, 0.0125 };

	cout <<"Adams-Bashford method:" << setprecision(6) << endl;
	cout << "y'=y and y(0)=1 -> y(3)=exp(3)=20,0855"
		<< endl;
	for (auto s : step)
	{
		double res = AdamsBashford(eq, 3, 0, 1, s);
		cout << "h=" << s << " y=" << res
			<< " err=" << abs(res - exp(3)) << endl;
	}
	cout << endl;

	cout << "y'=3x^2 and y(1)=1 -> y(-3)=(-3)^3=-27"
		<< endl;
	for (auto s : step)
	{
		double res = AdamsBashford(poly, -3, 1, 1, s);
		cout << "h=" << s << " y=" << res
			<< " err=" << abs(res + 27) << endl;
	}
	cout << endl;

	cout << "y'=xy^2-y/x and y(1)=-1 -> y(3)=-1/[(-3)^2]=-0.1111"
		<< endl;
	for (auto s : step)
	{
		double res = AdamsBashford(bernoulli, 3, 1, -1, -1 * s);
		cout << "h=" << s << " y=" <<
			res << " err=" << abs(res + 0.111) << endl;
	}
	cout << endl;
	
}