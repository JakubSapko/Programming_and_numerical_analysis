#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	vector<double> v = {12.54, -7.2, 9.09, 3.561, 0.0, -4.2135, 6.0009, 12.1, 2.45, -3.1};

	auto wypisz = [&v]()->void
	{
		for(auto em : v)
			cout << em << " ";
		cout << endl;
	};

	auto sum = [v]() -> double
	{
		double res = 0.0;
		for(auto em : v)
			res += em;
		return res;

	};

	auto av = [=]() -> double
	{
		return sum()/v.size();
	};

	auto std = [=]() -> double
	{
		double aver = av();
		double res = 0.0;
		for(auto em : v)
			res += (em - aver)*(em-aver);
		return sqrt(res/v.size());

	};

	auto max = [=]() -> double
	{
		return *std::max_element(v.begin(), v.end());
	};

	auto min = [=]() -> double
	{
		return *std::min_element(v.begin(), v.end());
	};

	auto square = [&v]() -> void
	{
		for(auto it=v.begin(); it != v.end(); ++it)
			*it = (*it) * (*it);
	};

	auto inverse = [&v]() -> void
	{
		for(auto it=v.begin(); it != v.end(); ++it)
		{
			if(*it != 0)
				*it = 1/(*it);
		}

	};

	auto multKtimes = [&v](double k) -> void
	{
		for(auto it=v.begin(); it != v.end(); ++it)
		{
			*it *= k;
		}
	};

	auto toInt = [&v]() -> void
	{
		for(auto it=v.begin(); it != v.end(); ++it)
		{
			*it = (int)*it;
		}
	};

	auto modify = [&v](double what, double treshold) -> void
	{
		for(int ii=0; ii<v.size(); ii++)
		{
			if(v[ii] > treshold)
			{
				v[ii] *= -1;
				v.insert(v.begin()+ii+1, what);
				ii++;
			}
		}
	};

	wypisz();

	cout << setprecision(3) << "SUMA=" << sum()
	<< " SREDNIA=" << av()
	<< " ODCHYLENIE=" << std()
	<< " MAX=" << max()
	<< " MIN=" << min()
	<< endl;

    square();
	wypisz();	
	inverse();
	wypisz();	
	multKtimes(1241.78);
	wypisz();	
	toInt();
	wypisz();	
	modify(-13, 50);
	wypisz();	
	return 0;
}