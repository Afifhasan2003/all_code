#include <bits/stdc++.h>
using namespace std;
 

int breaknum(int n,vector<int> &dp){
 
    if(dp[n]>-1) return dp[n];
    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 4;
    if(n==5) return 6;
    if(n==6) return 9;

    int mx=0;
    for (int i = 1; i <= n; i++)
    {
        mx=max(mx , i * breaknum(n-i,dp));
    }
    dp[n]=mx;
    cout<<"dp["<<n<<"]= "<<mx<<endl;
    return dp[n];

}


int integerBreak1(int n) {
    vector<int> dp(n+1,-1);
    
    int ans = breaknum(n,dp);

    // cout<<"dp[3]= "<<dp[6]<<endl;
    return ans;


}

//without recursion
int integerBreak(int n) {
    vector<int> dp(n+1,-1);
     dp[1] =1;
     dp[2] =1;
    if(n>=3) dp[3] =2;
    if(n>=4) dp[4] =4;
    if(n>=5) dp[5] =6;
    if(n>=6) dp[6]= 9;
    for (int i = 7; i <=n; i++)
    {
        int mx=0;
        for (int j = 1; j <=i; j++)
        {
            mx=max(mx, j * dp[i-j]);
        }
        dp[i] = mx;
    }
    return dp[n];
}



int main() {
    
    int n=10;
    cout<<endl;
    cout<<integerBreak(n)<<" ";

    return 0;
}