#include <iostream>
#include <utility>

using namespace std;

void egyptian(int n, int d)
{
	if (d == 0)
	{
		cout << "Denominator is equal to 0";
		return;
	}
	if (n == 0){
		cout << "0";
		return;
	}
	if (d%n == 0)
	{
		cout << "1/" << d/n;
		return;
	}
	if (n%d == 0)
	{
		cout << n/d;
		return;
	}
	if (n > d)
	{
		cout << n/d << " + ";
		egyptian(n%d, d);
		return;
	}
	int w = d/n + 1;
	cout << "1/" << w << " + ";
	egyptian(n*w-d, d*w);
}


int main(){

	int num [] = {3 , 7 , 0 , 7 , 123};
	int den [] = {4 , 9 , 8 , 0 , 43};
	for ( int ii =0; ii <5; ii ++){
		int n = num [ ii ];
		int d = den [ ii ];
		cout << n << "/" << d << " -> ";
		egyptian (n , d );
		cout << endl ;

}

return 0;
}
