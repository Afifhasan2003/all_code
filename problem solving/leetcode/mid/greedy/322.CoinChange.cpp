#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+2, 1e9);
    dp[0] = 0;
    
    for (int i = 0; i <= amount; i++)
    {

        for(auto a:coins)
        {
           if( (i-a)>=0 && dp[i-a]!=1e9 )
                dp[i] = min(dp[i], dp[i-a] + 1);
        }
            
    }
    if(dp[amount] !=1e9)
        return dp[amount];
    return -1;
}

int main() {
    

    vector<int> coins = {2};

    cout<<coinChange(coins,3)<<endl;


    return 0;
}