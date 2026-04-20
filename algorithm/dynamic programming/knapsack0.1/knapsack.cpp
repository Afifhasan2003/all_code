#include <bits/stdc++.h>
using namespace std;

int dp1[1005][1005];   

int knapsack_TopDown(int i, int W, vector<int>& wt, vector<int>& val, int n) { //W = remaining weight in bag, i = current index
    if (i == n || W == 0)
        return 0;

    if (dp1[i][W] != -1)
        return dp1[i][W];

    // if weight of current item is more than remaining capacity, skip it
    if (wt[i] > W) {
        return dp1[i][W] = knapsack_TopDown(i + 1, W, wt, val, n);
    }

    // choice: take or not take
    int take = val[i] + knapsack_TopDown(i + 1, W - wt[i], wt, val, n);
    int notTake = knapsack_TopDown(i + 1, W, wt, val, n);

    return dp1[i][W] = max(take, notTake);
}

int knapsack_BottomUp(int i, int W, vector<int>& wt, vector<int>& val, int n){

    vector<vector<int>> dp2(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {   // i -1 because dp2 is 1-indexed for items, but wt and val are 0-indexed
                dp2[i][w] = max(
                    dp2[i - 1][w], // not take
                    val[i - 1] + dp2[i - 1][w - wt[i - 1]] // take
                );
            } else {
                dp2[i][w] = dp2[i - 1][w];   // cannot take
            }
        }
    }
    return dp2[n][W];    
}

int knapsack_BottomUp_withDisplay(int i, int W, vector<int>& wt, vector<int>& val, int n){

    vector<vector<int>> dp2(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {   // can take
                dp2[i][w] = max(
                    dp2[i - 1][w], // not take
                    val[i - 1] + dp2[i - 1][w - wt[i - 1]] // take
                );
            } else {
                dp2[i][w] = dp2[i - 1][w];   // cannot take
            }
        }
    }

    //taken items list (indexes)
    vector<int> takenItems;
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp2[i][w] != dp2[i - 1][w]) { // item i-1 is taken
            takenItems.push_back(i - 1);
            w -= wt[i - 1]; // reduce remaining weight
        }
    }
    cout << "Taken items (indexes): ";
    for (int i = takenItems.size() - 1; i >= 0; i--) {
        cout << takenItems[i] << " ";
    }
    cout << endl;

    return dp2[n][W];    
}

int main() {
    int n = 3;
    vector<int> wt = {10, 20, 30,};
    vector<int> val = {60, 100, 120};
    int W = 40;

    memset(dp1, -1, sizeof(dp1)); //sizeof(dp)  gives the total number of bytes in the 2D array, so all entries get set to -1

    cout << "Max value = " << knapsack_TopDown(0, W, wt, val, n) << endl;
    cout << "Max value = " << knapsack_BottomUp(0, W, wt, val, n) << endl;


        cout << "Max value = " << knapsack_BottomUp_withDisplay(0, W, wt, val, n) << endl;

    return 0;
}
