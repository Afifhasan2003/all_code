#include<iostream>
#include<string>
using namespace std;

int bin(int n);
int bin2(int n);

int main(){


    int n;
    cout<<"Enter number: ";
    cin>>n;

    // cout<<"binary value is: "<<bin(n);
    cout<<"binary value is : "<<bin2(n);
    // bin2(n);

}
int bin(int n){                 //n=10

    int x=1,ans=0;              

    while (x<=n)
    {
        x=x*2;                 //x=1->2->4->8->16
    }
    x=x/2;                     //x=8

    while (x>0)    //not n>0       
    {
        int num=n/x;           //num=1               num=2/4=0            num=2/2=1          num=0/1=0
        ans=ans*10+num ;        //ans=0+1 ->         ans= 1*10 + 0        ans=10*10+1        ans=101*10+0
        n=n-num*x;              //n= 10-1*8=2        n=2                  n=2-2=0            n=0-0=0
        x=x/2;                  //x=4                x=2                  x=1                x=0
    }                                                                                //(now the loop will end)
    return ans;
    
}
int bin2(int n) {
    int ans=0,r=1;

    while (n>0)                                             //n=10
    {                                                       
        int rem=n%2;                                        //rem=0  rem=1      rem=0       rem=1
        ans=ans+ rem*r;  //MSB are at the last              //ans=0  ans=10     ans=10      ans=1010

        r=r*10;                                             //r=10   r=100      r=1000      r=10000
        n=n/2;                                              //n=5    n=2        n=1         n=0 (loop ends)
    }
    return ans;
    }