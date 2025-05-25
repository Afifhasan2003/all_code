#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // handle k > n
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int numberOfSpecificElement(vector<int> &nums,int target){
    int cnt = count(nums.begin(), nums.end(), target);
    return cnt;
}

void moveTargetToEnd(vector<int>& nums,int target) {
    
    stable_partition(nums.begin(), nums.end(), [target](int x) {        //lembda function
        return x != target;
    });

}


int main() {
    
    vector<int> nums = { 1,2,2,3,4,5,6,7};
    cout<<"rotate array by 3"<<endl;
    rotate(nums,3); for(int i=0 ; i<nums.size();i++) cout<<nums[i]<<" "; cout<<endl;

   
    cout<<"2 appears "<<numberOfSpecificElement(nums,2)<<" times"<<endl;

    




    return 0;
}