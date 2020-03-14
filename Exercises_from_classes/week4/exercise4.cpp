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

int fillGaps(int arr[], size_t sz)
{
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (size_t i = 0; i < sz; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int lmin = min;
    int w = min;
    do {
        for (size_t i = 0; i < sz; i++)
            if (arr[i] == min)
                arr[i] = w;
        w++;
        lmin = min;
        min = INT32_MAX;
        for (size_t i = 0; i < sz; i++)
            if (arr[i] <= min && arr[i] > lmin)
                min = arr[i];
    } while (lmin != max);
    return 0;
}

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

int fillWithPrimesVec(vector<int>& vec){
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j<INT_MAX; j++){
			if (isPrime(j)){
				vec.push_back(j);}
			else{continue;}
			}
		}
	
	return vec[0];
}

int main(){

int c[15];
size_t szc = sizeof(c)/sizeof(*c);
vector<int> d(szc,0);

cout << fillWithPrimesVec(d);

return 0;
}
