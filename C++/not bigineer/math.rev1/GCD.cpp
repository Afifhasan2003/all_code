#include<iostream>
using namespace std;


int gcdBySubstract(int a, int b);
int gcdByModulo(int a, int b);
int main() {


     int a,b;cin>>a>>b;
     cout<<gcdBySubstract(a,b);
     cout<<gcdByModulo(a,b);

return 0;
}

int gcdBySubstract(int a, int b){
    
    while (a!=b)
    {                                          // a=12,b=8
     if (a>b)                                     
     {                                          //a=12-8=4
        a=a-b;                                 // b=8-4
     }else b=b-a;
        
    }
    return a;
}
int gcdByModulo(int a, int b){
    while (b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}