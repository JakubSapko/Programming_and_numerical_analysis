#include <iostream>

using namespace std;

bool allDiff(const int arr[], size_t sz){
	for (int i = 0; i<sz; i++){
		int value = arr[i];
		for (int k = i+1; k<sz; k++){
			if (value == arr[k]){return false;}
			}
	}
	return true;
}
		

int main(){

int arr[]{1,2,3,4,5};
size_t sz = 5;

cout << allDiff(arr, sz);

return 0;
}
