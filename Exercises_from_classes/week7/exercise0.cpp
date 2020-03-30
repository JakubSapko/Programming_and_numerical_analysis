#include <iostream>
#include <vector>


using namespace std;


void binSearch(vector<int>* v, int z, int bg, int en);


int main(){
    int n, ele, toFind;
    vector<int> v;
    cout << "Podaj wymiar wektora: ";
    cin >> n;
    if (n<=0){
        cout << "Podaj dodatnia liczbe elementow wektora";
        return -1;
    }
    cout << "Podaj elementy: " << endl;
    for (int i=0; i<n; i++){
            cin >> ele;
            v.push_back(ele);
            if (i>0){
                if (v[i-1]>v[i]){
                    cout << "Elementy wektora maja byc wprowadzone w kolejnosci niemalajacej!";
                    break;
                }
            }
            /*cout << v[i] << endl;*/
    }
    cout << "Podaj liczbe do znalezienia: ";
    cin >> toFind;
    binSearch(&v, toFind, 0, n);
    return 0;
}


void binSearch(vector<int>* v, int z, int bg, int en){
    int w = abs(bg + en)/2;
    if (w - bg < 1 || en - w < 1){
        cout << "Liczba " << z << " nie pojawia sie we wprowadzonym wektorze." << endl;
        return;
    }
    if (v->at(w) == z){
        cout << "Liczba " << z << " pojawia sie w wektorze na komorce o indeksie rownym: " << w << endl;
        return;
    }
    else if (v->at(w) >= z){binSearch(v, z, bg, w);}
    else if (v->at(w) <= z){binSearch(v, z, w, en);}
}
