#include <iostream>

using namespace std;

template <typename T> void swap(T *xp, T *yp){
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}



template <typename T, typename W> void bubble(T arr[], W n){
	int i, j;
	for (i = 0; i< n-1; i++){
		for (j = 0; j< n-i-1; j++){
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}



void wypisz(int tab[10]){
	cout << "[";
	for (int i = 0; i< 10; i++){
		cout << tab[i] << " ";
	}
	cout << "]";
	cout << endl;
}

void wypisz(char tab[10]){
	cout << "[";
	for (int i = 0; i< 10; i++){
		cout << tab[i] << " ";
	}
	cout << "]";
	cout << endl;
}

int main(){

	int tabi[10] = {9, 4, 2, 1, 3, 6, 7, 2, 9, 0};
	char tabc[10] = {'b','g','z','x','a','y','r','y','y','e'};

	cout << "Tablica intow przed: " << endl;
	wypisz(tabi);
	cout << "Tablica charow przed: " << endl;
	wypisz(tabc);
	bubble(tabi, 10);
	cout << "Tablica intow po: " << endl;
	wypisz(tabi);
	bubble(tabc, 10);
	cout << "Tablica charow po: " << endl;
	wypisz(tabc);
return 0;
}
