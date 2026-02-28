#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int>& height) {
        
    int n= height.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    dp[1]=abs(height[1]- height[0]);

    for (int i = 2; i <n; i++)
    {
        dp[i] = min(
                 (dp[i-1] + abs(height[i] - height[i-1])),
                 (dp[i-2] + abs(height[i] - height[i-2]))
                 );

    }
    
    return dp[n-1];
        
    }
int main() {
    
    vector<int> height = {30, 20, 50, 10, 40};

    cout<<minCost(height)<<endl;

    return 0;
}