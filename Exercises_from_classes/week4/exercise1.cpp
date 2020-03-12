#include <iostream>
#include <algorithm>

using namespace std;

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix){
	in = 0;
	ix = 0;
	mn = *min_element(a, a+7);
	mx = *max_element(a, a+7);
	for (int i = 0; i < size; i++){
		if (a[i]==mn){in++;}
		else if (a[i]==mx){ix++;}
	}	

}


int main(){

	int a[]{2,3,4,2,7,4,7,2};
	size_t size = sizeof(a)/sizeof(*a);
	int mn, mx;
	size_t in, ix;
	minMaxRep(a, size, mn, in, mx, ix);
	cout << "Array: [ ";
	for (size_t i = 0; i<size; i++){
		cout << a[i] << " ";
	}
	cout << "]\n";
	cout << "Min = " << mn << " " << in << " times\n";
	cout << "Max = " << mx << " " << ix << " times\n";

return 0;
}
