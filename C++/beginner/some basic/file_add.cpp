#include<iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE                        //acronim~ if no defined 
    freopen("input.txt","r",stdin);             //file reopen
    freopen("output.txt","w",stdout);
    #endif 


    int a,b;
    cin>>a>>b;
    int sum=a+b;
    cout<<sum;
    

    return 0;
}