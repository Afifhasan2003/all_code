//example: 153: 1^3+5^3+3^3=153 sum of qube of each number is same as the number
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number ";
    cin>>n;
    int originalN=n;
    int sum=0;
    while (n>0)
    {
        int lastNum=n%10;
        sum+= pow(lastNum,3);
        n=n/10;

    }
    if (sum==originalN)
    {
        cout<<"armstrong number";
    }
    else{ 
        cout<<"not armstrong number";
    }


}