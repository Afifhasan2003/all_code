#include <bits/stdc++.h>
using namespace std;
int fib(int n){
        if(n==0) return 0;
        else if (n==1 || n==2) return 1;

        return fib(n-1) + fib(n-2);
        
}
int main() {
    int n=5;
    int ans= fib(n);
    cout<<endl<<ans<<endl;
    return 0;
}