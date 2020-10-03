#include <iostream>
#include <vector>


using namespace std;


double neville(const vector<double> &px, const vector<double> &py, double x) {
    double tab[px.size()][px.size()];

    for(int i=0; i<px.size(); i++){
        for(int j=0; j<px.size(); j++){
            tab[i][j]=0;
        }
    }

    for(int i=0; i<px.size(); i++){
        tab[i][0]=py[i];
    }

    for(int k=1; k<px.size(); k++){
        for(int i=k; i<px.size(); i++){
                tab[i][k]=((x-px[i-k])*tab[i][k-1]-(x-px[i])*tab[i-1][k-1])/(px[i]-px[i-k]);
            }
        }
    return tab[px.size()-1][px.size()-1];
}

int main() {
vector<double> px{-1, 0, 2, 3};
vector<double> py{-10, -2, 8, 46};
vector<double> x{0, -0.5, 1, 2.2};
for (auto i : x) {
cout << "p(" << i << ") = " << neville(px, py, i) << endl;
}
}
