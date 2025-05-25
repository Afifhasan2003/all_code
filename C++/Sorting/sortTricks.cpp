#include <bits/stdc++.h>
using namespace std;

bool checkRotatedSortedArray(vector<int> &nums){
    int count = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if(nums[i]>nums[(i+1) % n]) count++;
        }
        if(count>1){
            return false;
        }
        return true;
}
int main() {
    vector<int> arr = {5,6,7,1,2,3,4};
   if( checkRotatedSortedArray(arr)) cout<<"yes"<<endl;

    return 0;
}