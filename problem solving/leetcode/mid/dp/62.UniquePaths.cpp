#include <bits/stdc++.h>
using namespace std;

int helperfunction(int m,int n,vector<vector<int>> &dp){
    if(m==0) return dp[0][n]; //if reached top of the grid, then we only have one path
    if(n==0) return dp[m][0];

    if(dp[m][n] != -1)
         return dp[m][n];

    int left = helperfunction(m,n-1,dp);   //dont need to assign dp[m][n-1] because we are passing dp by reference, so it will be updated in the recursive calls
    int up = helperfunction(m-1,n,dp);  //moving up down
    
    return dp[m][n] = left + up;
}

int uniquePaths(int m, int n) {
        m--; n--; //we are using 0 based indexing, so we need to decrement m and n by 1

    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i]=1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0]=1;
    }
    
    return helperfunction(m,n,dp);


}
int main() {
    
    cout<<uniquePaths(3,7)<<endl;

    return 0;
}