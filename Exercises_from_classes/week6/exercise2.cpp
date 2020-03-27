#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print(const vector<T> &v){
	cout << " [ ";
	for (const auto &i : v){
		cout << i << " ";
	}
	cout << "]" << endl;
}
	
template <typename W> void minMaxRep(const vector<W> &v, W& mn, int& in, W& mx, int& ix){
	if(v.empty()){
		cout << "Wektor nie posiada zadnych wartosci." << endl;
		return;}
	else if(v.size()==1){
		in = 1;
		ix = 1;
		mn = v[0];
		mx = v[0];
		cout << " Min = " << mn << " " << in << " times \n";
		cout << " Max = " << mx << " " << ix << " times \n";
	}
	else{
		in = 0;
		ix = 0;
		mn = v[0];
		mx = v[0];
		for (int i = 0; i < v.size(); i++){
			if (v[i]<mn){in = 1; mn = v[i];}
			else if (v[i]>mx){ix = 1; mx = v[i];}
			else if (v[i] == mn){in++;}  
			else if (v[i] == mx){ix++;}
		}
		cout << " Min = " << mn << " " << in << " times \n";
		cout << " Max = " << mx << " " << ix << " times \n";
	}
}

int main ()
{
	cout << " Int : ";
	print (vector <int >{ -1 , 2 , -2 , 5 , 3});
	cout << " Double : ";
	print (vector < double >{ -1 , 2 , -2 , 5 , 3});
	// jezeli argument szablonu nie jest jasny
	// trzeba go podac
	// w tym przypadku nie jest to konieczne
	// jawny argumeny szablonu :
	print < double >(vector <double >{ -1 , 2 , -2 , 5 , 3});
	cout << " Char : ";
	print (vector <char>{75 , 119 , 73 , 107 , 63});
	print (vector <const char*>{ "K", "W", "I", "K", "!"});
	cout << " Const char * : ";
	print (vector < const char * >{" One ", " does ", "not",
	" simply ", " learn ", " template ", "meta - programing " });
	int ix =0 , in =0;
	{
		int mn , mx ;
		vector <int > v { -1 , 1 , 2, -1 , 5 , 2 , 2 , -1};
		print ( v );
		minMaxRep (v , mn , in , mx , ix );
		cout << " Min = " << mn << " " << in << " times \n";
		cout << " Max = " << mx << " " << ix << " times \n";
	}
	{
		double mn , mx ;
		// dla leniwych , decltype (i) jest tym samym typem co i
		vector < decltype ( mn ) > v { -1.23 , 5.43 , -2.33 , 8.66 , -1.23 , 8.66};
		print ( v );
		minMaxRep (v , mn , in , mx , ix );
		cout << " Min = " << mn << " " << in << " times \n";
		cout << " Max = " << mx << " " << ix << " times \n";
	}
	cout << "Wektor z 1 wartoscia" << endl;
	int mn, mx;
	vector <int> v{2};
	minMaxRep(v, mn, in, mx, ix);
	cout << " Min = " << mn << " " << in << " times \n";
	cout << " Max = " << mx << " " << ix << " times \n";
	cout << "Pusty wektor:" << endl;
	int ma, mi, iz = 0, iw = 0;
	vector <int> z;
	minMaxRep(z, ma, iz, mi, iw);
return 0;
}
