#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {

    int n=nums.size();
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    dp[1]=nums[0];
    for (int i = 2; i <=n; i++)
    {
        dp[i]= max(
            (dp[i-2] + nums[i-1]),
            dp[i-1]
        );
    }
    
    return dp[n];

}
int main() {
    
    vector<int> nums={2,7,9,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}