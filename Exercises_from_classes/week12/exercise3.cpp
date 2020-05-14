#include<algorithm>
#include<iostream>
#include<vector>
#include<forward_list>
#include<list>

using namespace std;

template <class ForwardIt>
void selectionSort(ForwardIt begin,ForwardIt end){
    for (ForwardIt el = begin; el!=end; ++el){
        ForwardIt mi = el;
        for (ForwardIt el2 = el; el2!=end; ++el2){
            if(*el2<*mi){mi=el2;}
            iter_swap(el, mi);
        }
    }
}

int main(){
    vector<int> v={6,4,2,2,3,1};
    selectionSort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    forward_list<int> mylist={34,77,16,2};
    selectionSort(mylist.begin(),mylist.end());
    for(auto i:mylist){
        cout<<i<<" ";
    }
    cout<<endl;
    list<int> l={7,5,16,8};
    selectionSort(l.begin(),l.end());
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
