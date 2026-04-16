#include <iostream>
#include <vector>
using namespace std;

int maxSumInterval(vector<int>& a)
{
    int currentSum = a[0];
    int maxSum = a[0];

    for (int i = 1; i < a.size(); i++)
    {
        // Either extend the current interval or start new from a[i]
        currentSum = max(a[i], currentSum + a[i]);

        // Update best answer
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int maxSumInterval_withDisplay(vector<int>& a)
{
    int currentSum = a[0];
    int maxSum = a[0];

    int start = 0;        // final interval start
    int end = 0;          // final interval end
    int tempStart = 0;    // temporary start

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > currentSum + a[i])
        {
            currentSum = a[i];
            tempStart = i;   // start new interval
        }
        else
        {
            currentSum += a[i]; // extend interval
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    // print substring
    cout << "Max Sum Interval: ";
    for (int i = start; i <= end; i++)
        cout << a[i] << " ";
    cout << endl;

    return maxSum;
}

int main()
{
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    cout << "Max Sum Interval = " << maxSumInterval(nums) << endl;

    int ans = maxSumInterval_withDisplay(nums);
    cout << "Max Sum Interval with Substring = " << ans << endl;

    return 0;
}
