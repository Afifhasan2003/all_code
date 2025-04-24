#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter number";
    cin>>n;

    int ans=0,lastNum;

    while (n>0)
    {
        lastNum=n%10;    //reminder is the last digit
        ans=ans*10 + lastNum;       //everytime multiplied by 10. 
        n=n/10;             //n is int.so last digit will be lost
    }
    
    cout<<ans;


 //if number is zero, then its not reversing right
}