#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> temp = nums;
    sort(nums.begin(), nums.end());
    vector<int> ans;

    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        if ((nums[left] + nums[right]) == target)
        {
            ans.push_back(left);
            ans.push_back(right);
            break;
        }

        if ((nums[left] + nums[right]) > target)
            right--;
        if ((nums[left] + nums[right]) < target)
            left++;
    }
    ans[0] = find(temp.begin(), temp.end(), nums[ans[0]]) - temp.begin();

    ans[1] = temp.size() - 1 - (find(temp.rbegin(), temp.rend(), nums[ans[1]]) - temp.rbegin());

    return ans;
}

vector<int> twoSum2(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main()
{
    vector<int> vec = {3, 3};

    vector<int> ans;
    ans = twoSum(vec, 6);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}