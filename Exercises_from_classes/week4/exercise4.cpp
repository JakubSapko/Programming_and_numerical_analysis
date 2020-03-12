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

int main(){

size_t sz = 5;
int arr[sz];

cout << fillWithPrimes(arr, sz);

return 0;
}
