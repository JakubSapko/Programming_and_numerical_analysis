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

int numDiff(int arr[], int n) 
{ 
    int val = 1; 
    for (int i = 1; i < n; i++) { 
        int k = 0; 
        for (k = 0; k < i; k++) 
            if (arr[i] == arr[k]) 
                break; 
        if (i == k) 
            val++; 
    } 
    return val; 
} 

int main(){

int arr[]{1,1,2,3,3};
size_t sz = 5;

cout << numDiff(arr, sz);

return 0;
}
