#include<iostream>
using namespace std;

int main(){

    int a=10,b;

    //b=a++;  here b will be 10
    //b=++a;  here b will be 11 after increament


        //10    12
    b=    a++ + ++a;

    cout<<"b="<<b;

}