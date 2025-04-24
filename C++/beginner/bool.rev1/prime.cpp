#include<iostream>
using namespace std;

bool isPrime(int x);

int main(){
    int a,b;
    cout<<"Enter two number:";
    cin>>a>>b;

    for ( int i = a;i <= b; i++)
    {
        if (isPrime(i))         //either 0 or 1
        {
            cout<<i<<"\t";
        }
        
    }

}
bool isPrime(int x){

    for (int i = 2; i < x; i++)     //not i<=x  than x would be evenly devided by x and everything number will be ans
    {
        if (x%i==0)
        {
            return false;       //if false ,then the function will end here
        }
        
    }
    return true;

}