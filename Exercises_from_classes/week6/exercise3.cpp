#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

double neville (const std::vector<double> &px, const std::vector<double> &py, double x){

	double tab[px.size()][px.size()];

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

void polyCoeff(const std::vector<double> &px, const std::vector<double> &py, std::vector<double> &c){

	auto px_n=px;
	auto py_n=py;

	for(int k=0; k<px.size(); k++){

		c.push_back(neville(px_n, py_n, 0));

	auto py_m=py_n;
		py_n.clear();

		double min=INT_MAX;
		int ind=0;

		for(int i=0; i<px_n.size(); i=i+1){

			if(abs(px_n[i])<min){
			min=abs(px_n[i]);
			ind=i;
			}
		}

		px_n.erase(px_n.begin()+ind);
		py_m.erase(py_m.begin()+ind);

		for(int i=0; i<px_n.size(); i++){

		py_n.push_back((py_m[i]-c[k])/px_n[i]);

		}
	}
}

void printPoly(const std::vector<double> &c){

	void polyCoeff(const std::vector<double> &px, const std::vector<double> &py, std::vector<double> &c);

	for (int i=0; i<c.size(); i++){
        if (i == 0 && c[0]!=0){
            std::cout << c[0];
        }
        else{
            if (c[i] == 0){
                continue;
            }
            else if (c[i]>0){
                if(i>1){
                    if (c[i] != 1){
                        std::cout << "+" << c[i] << "*x^" << i;
                    }
                    else {
                        std :: cout << "+x^" << i;
                    }
                }
                else{
                    if (c[i] != 1){
                        std::cout << c[i] << "*x";
                    }
                    else {
                        std::cout << "+x";
                    }
                }
            }
            else{
                if(i>1){
                    if (c[i] != -1){
                        std::cout << c[i] << "*x^" << i;
                    }
                    else {
                        std :: cout << "-x^" << i;
                    }
                }
                else{
                    if (c[i] != -1){
                        std::cout << c[i] << "*x";
                    }
                    else {
                        std :: cout << "-x";
                    }
                }
            }
        }
	}
}

/*
void printPolynoCoeff(const std::vector<double> &c){

	//void polyCoeff(const std::vector<double> &px, const std::vector<double> &py, std::vector<double> &c);

	for (int i=0; i<c.size(); i++){
        if (i == 0 && c[0]!=0){
            std::cout << c[0];
        }
        else{
            if (c[i]>0){
                std::cout << "+" << c[i] << "*x^" << i;
            }
            else if (c[i] == 0){
                continue;
            }
            else{
            std::cout << c[i] << "*x^" << i;
            }
        }
	}

}*/

int main() {
//std::vector<double> a{-5, 1, -2, 3, 0, 1};
std::vector<double> px{-1, 0, 2, 3};
std::vector<double> py{1, 1, 7, 25};
std::vector<double> coef;
polyCoeff(px,py,coef);
for(auto i: coef){
std::cout<<i<<" "<<std::endl;
}
std :: cout << "y = ";
printPoly(coef);
//std :: cout << "y = ";
//printPoly(a);
return 0;
}
