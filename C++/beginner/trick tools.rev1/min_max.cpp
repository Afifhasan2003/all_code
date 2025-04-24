#include <iostream>
#include <climits>  //for INT_MIN & INT MAX

using namespace std;



int main()
{

    int n;
    cout<<"how many numbers: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    for (int i = 0; i < n; i++)
    {

        // if (maxNum < arr[i])
        // {
        //     maxNum = arr[i];
        // }
        maxNum=max(maxNum,arr[i]);  //the maximum value between maxNUm and arr[i] will be assigned to maxNum
        


        // if (minNum > arr[i])
        // {
        //     minNum = arr[i];
        // }
        minNum=min(minNum,arr[i]); //the minimum value between minNUm and arr[i] will be assigned to minNum
    }
    cout << "max=" << maxNum << endl;
    cout << "min=" << minNum;
}