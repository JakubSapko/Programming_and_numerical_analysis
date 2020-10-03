#include <iostream>
#include <vector>
using namespace std;

class Interpolator
{
private:
	vector<double> *x;
	vector<double>* y;
public:
	Interpolator()
	{
		x = nullptr;
		y = nullptr;
	}
	Interpolator(vector<double> &x, vector<double> &y)
	{
		if(x.size() != y.size())
		{
			std::cout << "[ERR] X and Y dimension mismatch!";
			exit(1);
		}
		this->x = new vector<double>(x);
		this->y = new vector<double>(y);
	}
	~Interpolator()
	{
		if(x) delete x;
		if(y) delete y;
	}
	double operator()(double val)
	{

		double sum = 0.;
		for(int ii=0; ii<x->size(); ii++)
		{
			double prod = 1.;
			for(int jj=0; jj<x->size(); jj++)
			{
				if(ii == jj)
					continue;
				prod *= (val - (*x)[jj])/((*x)[ii]-(*x)[jj]);
			}
			sum += ((*y)[ii]*prod); 
		}
		return sum;
	}
};

int main()
{
	vector<double> X;
	vector<double> Y;
	for(int ii = -20; ii<20; ii++)
	{	
		X.push_back(ii);
		Y.push_back( (ii-1)*(ii+2)*(ii+7) );
	}
	Interpolator interp(X,Y);
	for(int ii=-2; ii<7; ii++)
		cout << interp(ii+0.5) << " " << (ii+0.5-1)*(ii+0.5+2)*(ii+0.5+7) << std::endl;
	return 0;
}