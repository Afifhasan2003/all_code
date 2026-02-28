//houses are in cercular street, first and last are adjacent

#include <bits/stdc++.h>
using namespace std;

int robF(vector<int>& nums) {

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


int rob(vector<int>& nums) {

    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    vector<int> nums1(nums.begin(),nums.end()-1);
    vector<int> nums2(nums.begin()+1, nums.end());

    int ans1 = robF(nums1);
    int ans2 = robF(nums2);

    return max(ans1,ans2); 

}
int main() {
    
    vector<int> nums={1,2,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}