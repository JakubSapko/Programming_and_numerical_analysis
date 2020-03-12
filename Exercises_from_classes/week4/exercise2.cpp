#include <iostream>
#include <iomanip>

using namespace std;

int binSearchRec(const int a[], int what, int from, int to){
	while(from<=to){
		int mid = (from + to)/2;
		if (a[mid] == what){return mid;}
		if (a[mid] > what){return binSearchRec(a, what, from, mid-1);}
		if (a[mid] < what){return binSearchRec(a, what, mid+1, to);}
	}
	return -1;
}



int main(){

	int a[]{1, 4, 5, 7, 9, 10};
	size_t sz = sizeof(a)/sizeof(*a);
	for (int i = a[0]; i <= a[sz-1]; ++i){
		cout << "what=" << setw(2) << i << " ind="
			 << setw(2)
			 << binSearchRec(a, i, 0, sz) << endl;}
	cout << "**************\n";
	int b[]{-1,1,3,4,6};
	sz = sizeof(b)/sizeof(*b);
	for (int i = b[0]; i<=b[sz-1]; ++i){
		cout << "what=" << setw(2) << i << " ind="
			 << setw(2) << binSearchRec(b, i, 0, sz) << endl;}





return 0;
}
