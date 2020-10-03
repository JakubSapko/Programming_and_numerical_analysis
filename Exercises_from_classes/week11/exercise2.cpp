#include<algorithm>
#include<iostream>
#include<vector>
#include<forward_list>
#include<list>

using namespace std;

template <class ForwardIt>
void bubbleSort(ForwardIt begin,ForwardIt end){
    for(ForwardIt ele=begin;begin!=end;end=ele){
        ele = begin;
        ForwardIt ele1, ele2;
        for(ele1=begin, ele2=begin; ++ele2!=end;++ele1, ++ele2){
            if(*ele1>*ele2){
                iter_swap(ele1, ele2);
                ele = ele2;
            }
        }
    }
}





int main(){
    vector<int> v={6,4,2,2,3,1};
    bubbleSort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    forward_list<int> mylist={34,77,16,2};
    bubbleSort(mylist.begin(),mylist.end());
    for(auto i:mylist){
        cout<<i<<" ";
    }
    cout<<endl;
    list<int> l={7,5,16,8};
    bubbleSort(l.begin(),l.end());
    for(auto i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
