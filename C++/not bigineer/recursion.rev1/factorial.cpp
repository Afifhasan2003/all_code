#include<iostream>
using namespace std;


int fact(int n);
int main() {


     int n; cin>>n;
    cout<<fact(n);

return 0;
}
int fact(int n){
    if (n==0)
    {
        return 1;       //base case  //it has to be before the formula
    }
    
    return n* fact(n-1);        //here n is decresed by 1 each time
} 