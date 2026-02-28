#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    map<int,int> m;

    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }

    auto rit_end = m.rend();
    for (auto it = m.rbegin(); it != rit_end; it++) {
        long long tm = k;

        for (auto itt = next(it); itt != m.rend(); itt++) {
            int diff = it->first - itt->first;

            if ((long long)diff * itt->second <= tm) {
                it->second += itt->second;
                tm -= (long long)diff * itt->second;
            } else {
                it->second += tm / diff;
                break;
            }
        }
    }

    int mx = INT_MIN;
    for (auto &p : m) {
        mx = max(mx, p.second);
    }

    return mx;
}


int main()
{

    vector<int> num = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    cout << maxFrequency(num, 3056) << endl;

    return 0;
}