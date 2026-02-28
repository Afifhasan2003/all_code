//here from can just upto k steps
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& height, int k) {

    int n = height.size();
    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = max(0, i - k); j < i; j++) {
            dp[i] = min(dp[i],
                        dp[j] + abs(height[i] - height[j]));
        }
    }

    return dp[n - 1];
}

int main() {
    vector<int> height = {15, 4, 1, 14, 15};
    cout << minCost(height, 3) << endl;
    return 0;
}