#include<iostream>
using namespace std;

int fact(int a);

int main(){
    int n,r;
    cout<<"Enter n ";
    cin>>n;
    cout<<"Enter r";
    cin>>r;

    int nCr=fact(n)/(fact(n-r) * fact(r));

   
    cout<<"nCr="<<nCr;
   
}
int fact(int a){

    int fact=1;
    for (int i = 1; i <=a; i++)
    {
        fact=fact*i;
    }
    return fact;
}

//not working with big values