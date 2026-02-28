//here each  coin has finite supply

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, vector<int>& count, int amount) {

    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int idx = 0; idx < coins.size(); idx++) {
        int a = coins[idx];
        int cnt = count[idx];

        // backward loop = bounded behavior
        for (int i = amount; i >= 0; i--) {
            if (dp[i] != INF) {
                for (int k = 1; k <= cnt && i + k * a <= amount; k++) {
                    dp[i + k * a] = min(dp[i + k * a], dp[i] + k);
                }
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {2, 3, 5};
    vector<int> count = {1, 2, 1};   // only one coin of 2, two coins of 3, one coin of 5

    cout <<"Minimum number of coins required: " <<coinChange(coins, count, 13) << endl;    //13 = 2 + 3 + 3 + 5
    return 0;
}