#include <bits/stdc++.h>
using namespace std;

//top down approach
int combination1(int n,int r, vector<vector<int>> &dp){
    if(dp[n][r]>-1) return dp[n][r];
    if(r==n || r==0) return 1;
    if(r==1) return n;

    dp[n][r] = combination1(n-1,r-1,dp) + combination1(n-1,r,dp);
     return dp[n][r];
}

int combination2(int n,int r,vector<vector<int>> &dp){

    
    for (int i = 1; i <=n; i++)
    {

        for (int j = 0; j <=r; j++)
        {   
            
            if(j==0 || j==i) dp[i][j]=1;
            else if (j==1) dp[i][j] = i;
            else
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
        
    }
    
    return dp[n][r];
}

int main() {
    int n=5,r=3;
    vector<vector<int>> dp1(n+1,vector<int>(r+1,-1));  //n row, r column
    vector<vector<int>> dp2(n+1,vector<int>(r+1,-1));  //n row, r column
    cout<<combination1(n,r,dp1)<<endl;
    cout<<combination2(n,r,dp2)<<endl;

    return 0;
}