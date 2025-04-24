#include<iostream>
using namespace std;


#include<vector>


int main() {


     vector<char> alpha={'a','b','c','d'};
     cout<<"size of alpha "<<alpha.size()<<endl;

    alpha.push_back('e');
    cout<<"size after pushback "<<alpha.size()<<endl;
    cout<<"capacity after pushback "<<alpha.capacity()<<endl;
    for(char x:alpha){
        cout<<x<<" ";
    }cout<<endl;

    alpha.pop_back();
    cout<<"size after popback "<<alpha.size()<<endl;
    for(char x:alpha){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"front= "<<alpha.front()<<endl;
    cout<<"back= "<<alpha.back()<<endl;

    cout<<"value at 1= "<<alpha.at(1)<<endl;

return 0;
}