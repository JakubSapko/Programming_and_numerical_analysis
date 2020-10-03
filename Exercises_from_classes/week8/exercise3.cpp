#include <iostream>
#include <vector>


using namespace std;

vector <double>* centralDiff(const vector <double>* x, const vector <double>* y);


vector <double>* secondCentralDiff(const vector <double>* x, const vector <double>* y);


int main(){

    vector <double> x = { 1, 1.101 , 1.202 , 1.303 , 1.404 , 1.505 , 1.606 , 1.707 , 1.808 , 1.909 };
    vector <double> y = { 1.975 , 1.85955 , 1.72085 , 1.55678 , 1.36518 , 1.14394 , 0.890923 , 0.603991 , 0.281013 , -0.0801417 };
    cout << "first:" << endl;
    vector <double>* v = centralDiff(&x, &y);
    for (auto i : (*v)){
        cout << i << " ";
    }
    cout << endl;
    delete v;
    v = secondCentralDiff(&x, &y);
    cout << "second:" << endl;
    for (auto i : (*v)){
        cout << i << " ";
    }
    cout << endl;
    delete v;
return 0;
}


vector <double>* centralDiff(const vector <double>* x, const vector <double>* y){
    vector <double>* result;
    result = new vector<double>;
    int rozmiar = (*x).size();
    for(int i = 1; i<rozmiar-1; i++){
        double w = (y->at(i+1)-y->at(i-1))/(x->at(i+1)-x->at(i-1));
        result->push_back(w);
    }
    return result;
}


vector <double>* secondCentralDiff(const vector <double>* x, const vector <double>* y){
    vector <double>* result;
    result = new vector<double>;
    int rozmiar = (*x).size();
    for(int i = 1; i<rozmiar-1; i++){
        double w = (y->at(i+1)-2*y->at(i)+y->at(i-1))/((x->at(i+1)-x->at(i))*(x->at(i)-x->at(i-1)));
        result->push_back(w);
    }
    return result;
}
