#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        
    int n=nums.size();
    int i= nums.size()-1;
    int right=i;
    
    while (right>0 &&  nums[right]<=nums[right-1])
    {
        right--;
    }
    right--;
    if (right < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

   
    while (i > right && nums[i] <= nums[right]) i--;
    
    swap(nums[i], nums[right]);
    
   
    sort(nums.begin() + right + 1, nums.end());
    
    }

int main() {
    // vector<int> arr={5,2,5,4,3,2,1};
    vector<int> arr={1,2,3};

    nextPermutation(arr);
    //  next_permutation(arr.begin(),arr.end());        this is a library function


     for(auto num:arr) cout<<num<<" ";

    return 0;
}