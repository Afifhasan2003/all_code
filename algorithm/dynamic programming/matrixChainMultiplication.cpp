// matrixChainMultiplication
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int bottomUpApproach(vector<int> &dims, vector<vector<int>> &Split) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    Split.resize(n, vector<int>(n, 0));

    // l is current chain length
    for (int l = 2; l <= n; l++) { 
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    Split[i][j] = k; // Record the split point
                }
            }
        }
    }

 

    return dp[0][n-1]; // Minimum cost to multiply all matrices
}

void parenthesization(int i, int j, const vector<vector<int>> &Split) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    cout << "(";
    parenthesization(i, Split[i][j], Split);
    parenthesization(Split[i][j] + 1, j, Split);
    cout << ")";
}


//top-down approach with memoization
int topDownApproachUtil(int i, int j, const vector<int> &dims, vector<vector<int>> &dp, vector<vector<int>> &Split) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {

        int ik = topDownApproachUtil(i, k, dims, dp, Split);
        int kj = topDownApproachUtil(k + 1, j, dims, dp, Split);

        int cost = ik + kj + dims[i] * dims[k + 1] * dims[j + 1];
        if (cost < dp[i][j]) {
            dp[i][j] = cost;
            Split[i][j] = k; // Record the split point
        }
    }
    return dp[i][j];
}
int topDownApproach(const vector<int> &dims, vector<vector<int>> &Split) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, -1));
    Split.resize(n, vector<int>(n, 0));
    return topDownApproachUtil(0, n - 1, dims, dp, Split);
}

//parenthesization function is the same as above





int main() {
    // Example: matrices with dimensions 10x30, 30x5, 5x60 etc.
    vector<int> dims = {10, 30, 5, 60, 10 , 20, 30, 40, 30}; 
    vector<vector<int>> splits;

    int minCost = bottomUpApproach(dims, splits);
    cout << "Minimum number of multiplications: " << minCost << endl;

    cout << "Optimal Parenthesization: ";
    parenthesization(0, dims.size() - 2, splits);   // zero to last matrix index
    cout << endl;

    

    vector<vector<int>> topDownSplits;
    int topDownMinCost = topDownApproach(dims, topDownSplits);
    cout << "Minimum number of multiplications (Top-Down): " << topDownMinCost << endl;
    cout << "Optimal Parenthesization (Top-Down): ";
    parenthesization(0, dims.size() - 2, topDownSplits);
    cout << endl;

    return 0;
}
