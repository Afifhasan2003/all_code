#include <bits/stdc++.h>
using namespace std;



double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    if (n == 0 || capacity == 0) return 0.0;

    vector<pair<double,int>> unitVal;
    for (int i = 0; i < n; i++)
        unitVal.push_back({(double)val[i] / wt[i], wt[i]});

    sort(unitVal.begin(), unitVal.end(), greater<pair<double,int>>());

    double ans = 0.0;
    int i = 0;

    while (i < n && unitVal[i].second <= capacity) {
        ans += unitVal[i].first * unitVal[i].second;
        capacity -= unitVal[i].second;
        i++;
    }

    if (i < n && capacity > 0)
        ans += unitVal[i].first * capacity;

    return ans;
}

int main() {
    
    vector<int> val={500, 100, 120}, wt={30, 20, 25};
    int n = val.size();

    double  ans = fractionalKnapsack(val,wt,50);
    cout<< ans <<endl;
    return 0;
}