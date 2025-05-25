#include <bits/stdc++.h>
using namespace std;



void mergeArrays(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;       //creating vector everytime
    int left = low, right = mid+1;

    while (left<=mid && right<=high)
    {
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    
    
}


int tempLeft[1000];
int tempRight[1000];
void mergeArrays2(vector<int> &arr, int low, int mid , int high){

    for (int i = low; i <= mid; i++)
        tempLeft[i-low] = arr[i];
    tempLeft[mid - low +1] = INT_MAX;

    for(int i = mid+1; i<=high ; i++)   
        tempRight[i - mid - 1] = arr[i];
    tempRight[high - mid] = INT_MAX;

    int i=0, j=0 , arrLeft = low;

    while (tempLeft[i]<INT_MAX || tempRight[j]<INT_MAX)
    {
        if(tempLeft[i]<=tempRight[j]) arr[arrLeft++] = tempLeft[i++];
        else if(tempLeft[i]>tempRight[j]) arr[arrLeft++] = tempRight[j++];
    }
    
    
}

void mergesort(vector<int> &arr , int low, int high){
    if(low==high) return;

    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    // mergeArrays(arr,low,mid,high);
    mergeArrays2(arr,low, mid, high);
}




int main() {
    
    vector<int> arr = {2,3,5,1,6,1,2,14,25,5};
    mergesort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}