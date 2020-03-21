#include <iostream>
#include <cstring>

using namespace std;

void neville(const double xa[], const double ya[], size_t size, double x){
	double Q[size][size];
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			Q[i][j] = 0.0;
		}
	}
	for (int i = 0; i < size; i++){
		Q[i][0] = ya[i];
	}
	for (int i = 1; i < size; i++){
		for (int j = 1; j<= i; j++){
			Q[i][j] = ((x - xa[i-j])*(Q[i][j-1])-(x-xa[i])*(Q[i-1][j-1]))/(xa[i]-xa[i-j]);
	}
}
	for ( int i = 0; i< size; i++){
		for (int j = 0; j< size; j++){
			cout << Q[i][j];
		}
	cout << endl;
	}
}

int main(){

	double x[]{-1, 0, 1, 2}; // arguments
	double f[]{-5, -1, -1, 1}; //values for given arguments
	neville(x, f, 4, 3);

return 0;
}
