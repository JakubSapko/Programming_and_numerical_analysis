#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <functional>
using namespace std;

template <class T>
double eulerMethod(T f, double x, double x0, double y0, double step)
{
	double y = y0;
	if(x > x0)
		step = abs(step);
	else if (x < x0)
	{
		step = -1*abs(step);
	}
	else
		return y0;

	double formerSign = (x-x0)/abs(x-x0);
	double sign = formerSign;
	while(formerSign*sign == 1)
	{
		y += step * f(x0, y);
		x0 += step;
		sign = (x-x0)/abs(x-x0);
	}
	return y;
}

template <class T>
double midPoint(T f, double x, double x0, double y0, double step)
{
	double y = y0;
	if(x > x0)
		step = abs(step);
	else if (x < x0)
	{
		step = -1*abs(step);
	}
	else
		return y0;

	double formerSign = (x-x0)/abs(x-x0);
	double sign = formerSign;
	while(formerSign*sign == 1)
	{
		y += step * f(x0+step/2., y+step/2.*f(x0, y));
		x0 += step;
		sign = (x-x0)/abs(x-x0);
	}
	return y;
}

template <class T>
double heun(T f, double x, double x0, double y0, double step)
{
	double y = y0;
	if(x > x0)
		step = abs(step);
	else if (x < x0)
	{
		step = -1*abs(step);
	}
	else
		return y0;

	double formerSign = (x-x0)/abs(x-x0);
	double sign = formerSign;
	while(formerSign*sign == 1)
	{
		double val = y + step*f(x0, y);
		y += step/2. * (f(x0,y) + f(x0+step, val));
		x0 += step;
		sign = (x-x0)/abs(x-x0);
	}
	return y;
}

double eq(double x, double y)
{
	return y;
}

double poly(double x, double y)
{
	return 3*x*x;
}

double bernoulli(double x, double y)
{
	if(x==0)
		return NAN;
	else
		return x*y*y-y/x;
}

//jaki fajny szablon!
template <typename T>
using funcPointer = double (*)(T, double, double, double, double);

int main()
{
	vector<double> step = {1., 0.25, 0.1, 0.05, 0.025, 0.0125};
	vector<string> names = {"EULER", "MIDPOINT", "HEUN"};
	//jaki fajny wektor!
	vector<funcPointer<double (*)(double, double)> > methods = {eulerMethod, midPoint, heun};
	for(int ii=0; ii<methods.size(); ii++)
	{
		cout << names[ii] << " METHOD:" << setprecision(6) << endl;
		cout << "y'=y and y(0)=1 -> y(4)=exp(4)=54.5982" << endl;
		for(auto s : step)
		{
			double res =  methods[ii](eq, 4, 0, 1, s);
			cout << "h=" << s << " y=" << res << " err=" << abs(res - exp(4)) << endl;
		}
		cout << endl;

		cout << "y'=3x^2 and y(1)=1 -> y(-2)=(-2)^3=-8" << endl;
		for(auto s : step)
		{
			double res =  methods[ii](poly, -2, 1, 1, s);
			cout << "h=" << s << " y=" << res << " err=" << abs(res + 8) << endl;
		}
		cout << endl;
	
		cout << "y'=xy^2-y/x and y(1)=-1 -> y(2)=-1/[(-2)^2]=-0.25" << endl;
		for(auto s : step)
		{
			double res =  methods[ii](bernoulli, 2, 1, -1, -1*s);
			cout << "h=" << s << " y=" << res << " err=" << abs(res + 0.125) << endl;
		}
		cout << endl;
	}
}