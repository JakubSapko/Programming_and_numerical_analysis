#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//----Functions for arrays----//

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


//----Functions for vectors----//

bool allDiffVec(const vector<int>& vec){
	for (int i = 0; i<vec.size(); i++){
		int val = vec[i];
		for ( int k = i+1; k<vec.size(); k++){
			if (vec[k] == val){return false;}
		}
	}
	return true;
}

int numDiffVec(const vector<int>& vec){
    int val = 1; 
    for (int i = 1; i < vec.size(); i++) { 
        int k = 0; 
        for (k = 0; k < i; k++) 
            if (vec[i] == vec[k]) 
                break; 
        if (i == k) 
            val++; 
    } 
    return val; 
}

int main(){

int a[]{1, 1, 1, 3, 1, 1, 2};
size_t sza = sizeof(a)/sizeof(*a);
vector<int> b(a, a+sza);


cout << numDiffVec(b);

return 0;
}
