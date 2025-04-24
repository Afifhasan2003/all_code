//sum of positive numbers till n

#include<iostream>
using namespace std;


int sumfunc(int n);
int main() {


     int n;
     cin>>n;

    cout<<sumfunc(n);

return 0;
}
int sumfunc(int n){
    
    if (n==0)
    {
        return 0;   //base case
    }
    
    int prevsum=sumfunc(n-1);
    return n+ prevsum;
}