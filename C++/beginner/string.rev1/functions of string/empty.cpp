#include<iostream>
#include<string>
using namespace   std;
int main() {

string s1;


if(s1.empty()){             //if s1 has nothing inside then s1.empty()  is true 
    cout<<"YOU have not given input"<<endl;
}

string s2="hehe";

if ( ! s2.empty())          //s2 has something inside.so s2.empty is false 
{
    cout<<"you entered: "<<s2<<endl;
}

s2.clear();

if (s2.empty())
{
        cout<<"no input value availabe";
}



return 0;
}
