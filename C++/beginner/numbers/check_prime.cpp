#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter number: ";
    cin>>a;
    int i;
    for (i =2; i < a; i++){
        if (a %i ==0)
        {
            cout<<a<<"is not prime";
            break;
        }
        
    }

    if(i==a){
        cout<<a<<"is prime";
    }

}