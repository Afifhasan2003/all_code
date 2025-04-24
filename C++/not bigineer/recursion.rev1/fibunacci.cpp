#include<iostream>
using namespace std;

int fib(int n);

int main() {


     int n;cin>>n;

     cout<<fib(n);


return 0;
}
int fib(int n){
    if (n==0)
    {
        return 0;
    } else if (n==1)
    {
        return 1;
    }
    
    
    return fib(n-1)+ fib(n-2);
}

//0th element is 0 ,1st element is 1