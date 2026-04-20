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

int fibBottomUp(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;

    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1]+ dp[i-2];
    }

    return dp[n];
    
}
int main() {
    int n=10;
    vector<int> dp (n+1,-1);

    cout<<fibTopDown(n,dp)<<endl;
    cout<<fibBottomUp(n) <<endl;


    return 0;
}