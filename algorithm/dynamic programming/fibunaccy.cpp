#include <bits/stdc++.h>
using namespace std;

int fibTopDown(int n,vector<int> &dp){
    if(dp[n] > -1) return dp[n];
    if(n==0) return 0;
    if(n==1) return 1;
    else {
        dp[n] = fibTopDown(n-1,dp) + fibTopDown(n-2,dp);
        return dp[n];
    }
    
}
int main() {
    int n=10;
    vector<int> dp (n+1,-1);

    cout<<fibTopDown(n,dp)<<endl;


    return 0;
}