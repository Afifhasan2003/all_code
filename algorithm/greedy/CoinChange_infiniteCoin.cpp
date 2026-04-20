// Coin Change with Infinite Coins
// question: what is the minimum number of coins required to make up a given amount?

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9; // --- IGNORE ---

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 2, inf);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++)
    {

        for (auto a : coins)
        {
            if ((i - a) >= 0 && dp[i - a] != 1e9)
                dp[i] = min(dp[i], dp[i - a] + 1);
        }
    }
    if (dp[amount] != 1e9)
        return dp[amount];
    return -1;
}

int coinChangeReq(vector<int> &coins, int ammount, vector<int> &dp)
{

    if(ammount==0) return 0;
    if(ammount < 0) return 1e9;
    if (dp[ammount] != (int)1e9)
        return dp[ammount];

    int val = inf;
    for (auto c : coins)
    {
        int temp = coinChangeReq(coins, ammount - c, dp);
        if(temp != inf)
            val = min(val, temp + 1);
    }
    dp[ammount] = val;
    return dp[ammount];
}

int main()
{

    vector<int> coins = {2, 3, 5};
    int ammount = 11;

    cout << coinChange(coins, ammount) << endl;

    vector<int> dp(ammount + 2, inf);
    cout<<coinChangeReq(coins, ammount, dp);

    return 0;
}