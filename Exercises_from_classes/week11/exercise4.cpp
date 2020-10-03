#include<algorithm>
#include<iostream>
#include<vector>
#include<forward_list>
#include<list>

using namespace std;

template <class ForwardIt>
void insertionSort(ForwardIt begin, ForwardIt end){
    for(ForwardIt el = begin; el!=end; el++){
        ForwardIt xd = upper_bound(begin, el, *el);
        rotate(xd, el, next(el));
    }
}



int main() {
    vector<int> v={6,4,2,2,3,1};
    insertionSort(v.begin(),v.end());
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
    forward_list<int> mylist={34,77,16,2};
    insertionSort(mylist.begin(),mylist.end());
    for (auto i:mylist){
        cout<<i<<" ";
    }
    cout<<endl;
    list<int> l={7,5,16,8,-3};
    insertionSort(l.begin(),l.end());
    for(auto i:l){
        cout<<i<<" ";
    }
    cout << endl;
    return 0;
}
