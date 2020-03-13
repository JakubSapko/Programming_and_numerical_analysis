#include <iostream>
#include <algorithm>

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

bool isPrime(int n){                           
	if (n<=1){return false;}
	for (int i = 2; i < n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;}

int fillWithPrimes(int arr[], size_t sz){
	bool a = true;
	int i = 1;
	int j = 0;
	while (a){
		if (isPrime(i)){
			arr[j] = i;
			j++;
			if (j==sz){a = false;}}
		i++;
	}
	return arr[sz-1];
}

/*int fillGaps(int arr[], size_t sz){
	int min = *min_element(arr, arr+sz);
	for (int i = 0; i < sz; i++){
		if (arr[i] == min){continue;}
		else 
	}
	return arr[sz-1];
	}
*/

size_t blockRem(int arr[], size_t sz, size_t from, size_t to){
	int i, j = 0;
	for (i = 0; i<sz; i++){
		if (i<=from || i>to){
			arr[j] = arr[i];
			j++;
		}
	}
	return j;
}		

int main(){

size_t sz = 6;
int arr[]{1, 2, 3, 4, 5, 6};

cout << blockRem(arr, sz, 2, 4);

return 0;
}
