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
    int min = INT_MAX;
    int max = INT_MIN;
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
        min = INT_MAX;
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
	bool a = true;
	int i = 1;
	int j = 0;
	while (a){
		if (isPrime(i)){
			vec[j] = i;
			j++;
			if (j==vec.size()){a = false;}}
		i++;
	}
	return vec[0];
}

int fillGapsVec(vector<int>& vec)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < min)
            min = vec[i];
        if (vec[i] > max)
            max = vec[i];
    }
    int lmin = min;
    int w = min;
    do {
        for (size_t i = 0; i < vec.size(); i++)
            if (vec[i] == min)
                vec[i] = w;
        w++;
        lmin = min;
        min = INT_MAX;
        for (size_t i = 0; i < vec.size(); i++)
            if (vec[i] <= min && vec[i] > lmin)
                min = vec[i];
    } while (lmin != max);
    return 0;
}

size_t blockRem(vector<int>& vec, size_t from, size_t to){
	int i, j = 0;
	for (i = 0; i<vec.size(); i++){
		if (i<=from || i>to){
			vec[j] = vec[i];
			j++;
		}
	}
	return j;
}		

//----FIN----//

int main(){

int a[]{3, 2, 3, 2, 5};
size_t sza = sizeof(a)/sizeof(*a);
vector<int> b(a, a+sza);
cout << "allDiff: " << boolalpha
	 << "a - " << allDiff(a, sza) << ", "
	 << "b - " << allDiffVec(b) << "\n";
cout << "numDiff: "
	 << "a - " << numDiff(a, sza) << ", "
	 << "b - " << numDiffVec(b) << "\n";

int c[15];
size_t szc = sizeof(c)/sizeof(*c);
vector<int> d(szc, 0);
auto lastc = fillWithPrimes(c, szc);
cout << "Primes: ";
for (auto x : c ) cout << x << " ";
cout << "\n Last: " << lastc << "\n";
auto lastd = fillWithPrimesVec(d);
cout << "Primes: ";
for (auto x : d) cout << x << " ";
cout << "\n Last: " << lastd << "\n";

int e[]{-3, 3, 5, -2, 8, 5, 8, -2};
size_t sze = sizeof(e)/sizeof(*e);
vector<int> f(e, e+sze);
cout << "Filling gaps: ";
for (auto x : e) cout << x << " ";
auto laste = fillGaps(e, sze);
cout << "\n becomes: ";
for (auto x : e) cout << x << " ";
cout << "\n max value: " << laste << "\n";
cout << "Filling gaps: ";
for (auto x : f ) cout << x << " ";
auto lastf = fillGapsVec(f);
cout <<"\n becomes: ";
for (auto x : f) cout << x << " ";
cout << "\n max value: " << lastf << "\n";

int g[]{1, 2, 3, 4, 5, 6, 7};
size_t szg = sizeof(g)/sizeof(*g);
vector<int> h(g, g+szg);
cout << "Original arr: ";
for (auto x : g) cout << x << " ";
auto newDimg = blockRem(g, szg, 2, 5);
cout << "\nAfter 'removing': ";
for (size_t i = 0; i < newDimg; ++i)
cout << g[i] << " ";
cout << "\n";
cout << "Original vec: ";
for (auto x : h) cout << x << " ";
auto newDimh = blockRemVec(h, 2, 5);
cout << "\nAfter removing: ";
// vector has been resized by the function
for (auto x : h) cout << x << " ";
cout << "\n";


return 0;
}
