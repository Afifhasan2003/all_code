#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {

    int left=0, right=0, sum=0 ,n=nums.size();
    int ans=INT_MIN;
    int i,j;
    while (right<n)
    {
        sum +=nums[right];

        if(sum>ans){
            i=left;
            j=right+1;
        }
        ans= max(ans,sum);

        if(sum<0){
            sum = 0;
            left = right+1;
            
        }
        

        right++;
    }
    
    for (int k = i; k < j; k++)
    {
        cout<<nums[k]<<" ";
    }
    
    return ans;

    
}
int main() {
    
    vector<int> vec={-2,1,-3,4,-1,2,1,-5,4};

    maxSubArray(vec);
    return 0;
}