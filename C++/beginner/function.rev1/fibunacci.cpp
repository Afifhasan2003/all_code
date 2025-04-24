#include<iostream>
using namespace std;

    void fib(int n);

int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;

    fib(a);
}
    void fib(int n){
        int t1=0,t2=1,tn;
        for (int i = 0; i < n; i++)
        {
            cout<<t1<<"\t";
            tn=t1+t2;
            t1=t2;
            t2=tn;
          //return;  //absoutely no,, then funtion would stop after just one rotation
        }
        return;
    }