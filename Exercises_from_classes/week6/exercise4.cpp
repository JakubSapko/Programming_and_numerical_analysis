#include <iostream>
#include <vector>

using namespace std;


typedef vector<double> vec;
typedef vector<vec> matrix;

bool wymiary(matrix M, int &n, int &m){
	n = M.size();
	if ( n == 0){return false;}
	m = M[0].size();
	for(int i = 0; i < n; i++){
		if (M[i].size() != m){return false;}
	}
	return true;
}


void wypisz(const matrix& M){
	int n = M.size();
	int m = M[0].size();
	if(wymiary(M, n, m)){
		for (int i = 0; i <	n; i++){
			for (int j = 0; j < m; j++){
				cout << M[i][j] << " ";
			}
		cout << endl;
		}
	}
	else{return;}	
}

void skalar(matrix& M, double s){
	int n = M.size();
	int m = M[0].size();
	if(wymiary(M, n, m)){
	for(int i = 0; i<n; i++){
		for (int j = 0; j < m; j++){
			M[i][j] = s*M[i][j];
		}
	}
	}
	else{return;}
}

void odejmowanie(const matrix& A, const matrix& B, matrix& wynik){
	int n = A.size();
	int m = A[0].size();
	int a = B.size();
	int b = B[0].size();
	if( (wymiary(A, n, m) && wymiary(B, a, b)) && ((n == a) && (m == b))){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				wynik[i][j] = A[i][j] - B[i][j];
			}	
		}
	}
	else{return;}		
}

void dodawanie(const matrix& A, const matrix& B, matrix& wynik){
	int n = A.size();
	int m = A[0].size();
	int a = B.size();
	int b = B[0].size();
	if( (wymiary(A, n, m) && wymiary(B, a, b)) && ((n == a) && (m == b))){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				wynik[i][j] = A[i][j] + B[i][j];
			}	
		}
	}
	else{return;}		
}

void mnozenie(const matrix& A, const matrix& B, matrix& result){
	int a = A.size();
	int b = A[0].size();
	int c = B.size();
	int d = B[0].size();
	if (a!=d || b != c)
	{
		cout << "Niepoprawny wymiar macierzy" << endl;
	}
	else{
		for (int i = 0; i<a; i++){
			for (int j = 0; j<a; j++){
				for (int k = 0; k<a; k++){
					result[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
}

void potegowanie(matrix& A, int n){
	for (int i = 0; i<n; i++){
		mnozenie(A, A, A);
	}
}


int main(){

vec v1 ({1. , 2. , 3. , 4.});
vec v2 ({5. , 6. , 7. , 8.});
vec v3 ({9. , 10. , 11. , 12.});
vec v4 ({0. , 0., 0., 0.});
matrix M ({ v1 , v2 , v3 });
matrix N = M ;
matrix O ({v4, v4, v4});
matrix P;
matrix Q = O;
matrix R = O;
P = matrix ( { vec ({2.0 , 0.0 , 0.0}) , vec ({1.0 , 0.0 , 1.0}) , vec ({0.0 , 0.0 , -1.0}) , vec ({0.0 , 0.0 , 0.0}) } );
cout << "M:" << endl ;
wypisz ( M );
cout << "P:" << endl ;
wypisz ( P );
skalar (M , 0.5);
cout << "M =0.5 M:" << endl ;
wypisz ( M );
odejmowanie (M , N , O );
cout << "O=M-N:" << endl ;
wypisz ( O );
dodawanie (M , N , Q );
cout << "Q=M+N:" << endl ;
wypisz ( Q );
/*potegowanie (Q , 2);
cout << "Q=Q*Q: ( nieudane )" << endl ;
wypisz ( Q );
*/
mnozenie (O , P, R);
cout << "R=O*P:" << endl ;
wypisz ( R );
potegowanie (R , 2);
cout << "R=R*R:" << endl ;
wypisz ( R );
potegowanie (R , 3);
cout << "R=R*R*R:" << endl ;
wypisz ( R );
return 0;}






