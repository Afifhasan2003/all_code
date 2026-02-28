#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

    int n=nums.size();
    sort(nums.begin(),nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i]!=i)
        {
            return i;
        }
        
    }

    return n;
    

}


int main() {
    
    vector<int> nums={2,3,1,5,0};
    cout<<missingNumber(nums)<<endl;

    return 0;
}