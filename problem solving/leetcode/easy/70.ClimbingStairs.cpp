#include <bits/stdc++.h>
using namespace std;

int jump(int n, vector<int>&dp){

    if(n==0) return dp[0] =0;
    if(n==1) return dp[1] = 1;
    if(n==2) return dp[2] = 2;
    if(n==3) return dp[3]= 3;

    int oneStep = jump(n-1,dp);
    int twoStep = jump(n-2,dp);
    int totalways = oneStep + twoStep;
    dp[n] = totalways;

    // cout<<"dp["<<n<<"]= "<<dp[n]<<endl; 

    return totalways;
}
int jump2(int n, vector<int>&dp){


    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;


    for (int i = 4; i <=n; i++)
    {
        dp[i] = dp[i-2] + dp[i-1]; 
    }
    

    

    return dp[n];
}


int climbStairs(int n) {
    
    if(n==1) return 1;
    if(n==2) return 2;

    vector<int> dp(n+1,-1);
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    
    for (int i = 3; i <=n; i++)
    {
        dp[i] = dp[i-2] + dp[i-1]; 
    }
    return dp[n];
    }


int main() {
    
    cout<<climbStairs(5)<<endl;
    return 0;
}