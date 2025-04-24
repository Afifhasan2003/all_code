#include<iostream>
#include<algorithm>
using namespace std;

bool check(int a,int b ,int c);

int main(){

    int x,y,z;
    cin>>x>>y>>z;

    if (check(x,y,z))
    {
        cout<<"pythagorian triplet";
    }
    else cout<<" not pythagorian triplet";
    

}
bool check(int a,int b ,int c){
    int q,r;
    int p=max(a, max(b,c));

    if (p==a)
    {
        q=b;
        r=c;
    }
    else if (p==b)
    {
        q=a;
        r=c;   
    } else {
        q=a;
        r=b;
    }
    
    if (p*p==q*q + r*r)
    {
        return true;
    }   
    else return false;

}