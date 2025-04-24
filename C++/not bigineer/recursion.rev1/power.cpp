#include<iostream>
using namespace std;


int power(int a, int n); 
int main() {


     int a,n;   // n to the power a
    cin>>a>>n;

    cout<<power(a,n);

return 0;
}

int power(int a, int n){
    if (a==0)
    {
        return 1;       //base case
    }
    
    return n*power((a-1),n);
}