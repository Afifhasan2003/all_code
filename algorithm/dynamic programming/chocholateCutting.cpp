//gpt

#include <bits/stdc++.h>
using namespace std;

int maxProfitFromChocolateCutting(vector<vector<int>> &chocolatePrices, vector<int> &dp, int n, vector<int> &cut1){
    if(dp[n]>-1) return dp[n];
    if(n==0) return 0;

    int mx=0;
    for (int i = 1; i <= n; i++)
    {
        int keep=maxProfitFromChocolateCutting(chocolatePrices,dp,n-i,cut1);
        for (int j = 0; j < chocolatePrices.size(); j++)
        {
            if(mx < chocolatePrices[j][i] + keep){
                mx= chocolatePrices[j][i] + keep;
                cut1[n]=i;
            }
        }
        
    }
    
    
    dp[n] = mx;
    return mx;
}

int maxProfitFromChocolateCutting_bottomUp(vector<vector<int>> &chocolatePrices, vector<int> &dp, int n, vector<int> &cut1){
    if(n==0) return 0;
    dp[0]=0;
    for (int i = 1; i <=n; i++)
    {
        int mx=0;
        int cutPosition=0;
        for (int j = 1; j <=i; j++)
        {
            int currentMax=0;
            for (int k = 0; k < chocolatePrices.size(); k++)
            {
                currentMax=max(currentMax,chocolatePrices[k][j]);
            }
            if(mx < currentMax + dp[i-j]){
                mx=currentMax + dp[i-j];
                cutPosition=j;
            }
        }
        dp[i]=mx;
        cut1[i]=cutPosition;
    }
}

int main() {
    vector<vector<int>> chocolatePrices = {     //price of chocolate of size i in jth shop
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 5, 8, 9, 10, 17, 17},
        {0, 2, 5, 7, 8, 9, 15, 16},
        {0, 3, 5, 6, 7, 8, 14, 15},
        {0, 4, 5, 6, 7, 8, 13, 14},
        {0, 5, 5, 6, 7, 8, 12, 13},
        {0, 6, 5, 6, 7, 8, 11, 12},
        {0, 7, 5, 6, 7, 8, 10 ,11}
    };

    int n=7; // length of rod
    return 0;
}