#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";cin>>n;

    int ans=0,r=1;
    while (n>0)
    {
        int lastNUm=n%10;
       if (lastNUm<8)
       {
         ans =ans + lastNUm*r;
       }else {cout<<"number invalid"<<endl;
            
       }
       
        r=r*8;
        n=n/10;
    }
    
    cout<<"Deciman value is: "<<ans;
}