#include <iostream>
#include <utility>

using namespace std;

void egyptian(int n, int d)
{
	if (d == 0 || n == 0)
		return;
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
/*	pair<int,int> fracs[]{
	{3,4}, {7,9}, {0,8}, {7,0}, {123, 43}
	};
	for (auto[n, d] : fracs){
		cout << n << '/' << d << " -> ";
		egyptian(n, d);
		cout << endl;
	}
*/
egyptian(3, 4);
return 0;
}
