#include<iostream>
using namespace std;

int deci(int a);

int main(){
    int bin;
    cout<<"Enter binary number: ";
    cin>>bin;

    cout<<"Decimal value is : "<<deci(bin);

}
int deci(int a){

    int x=1, ans=0;

    while (a>0)
    {
        int lastNum=a%10;
        ans=ans+lastNum*x;
        x=x*2;
        a=a/10;
    }
    return ans;
    
}