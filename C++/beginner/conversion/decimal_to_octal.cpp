#include<iostream>
using namespace std;
int decToOct(int n);
int decToOct2(int n);

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    cout<<"Octal value is: "<<decToOct(n)<<endl;
    cout<<"Octal value is: "<<decToOct2(n)<<endl;

}
int decToOct(int n){

    int ans=0,r=1;

    while (r<=n)
    {
        r=r*8;
    }   r=r/8;
    
    while (r>0)
    {
        int num=n/r;
        ans=ans*10+num;
        n=n-num*r;
        r=r/8;
    }
    return ans;
    
}

int decToOct2(int n) {
    int ans = 0, r = 1;

    while (n > 0) {
        int remainder = n % 8;
        ans = ans + remainder * r;
        n = n / 8;
        r = r * 10;
    }

    return ans;
    }