#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){

    int pivot = arr[low]; //or we could take any element from the array
    int i = low;
    int j= high;

    //  J finds the numbers smaller than pivot, i finds the numbers bigger than pivot.
    //when i and j finds a number, then they swap.. 
    //when j crosses i, thats the last number smaller than pivot.. we swap it with pivot.. 
    //now every number before pivot is smaller that pivot and numbers are bigger after pivot. 
    //then we return the position of pivot, so the smaller part and the bigger part can go through the same step
    while (i<j)
    {
        while (pivot >= arr[i] && i< high)
        {
            i++;
        }
        while (pivot <= arr[j] && j > low)
        {
           j--;
        }
        
        if(i<j) swap( arr[i] , arr[j]);
 
    }
    swap(arr[j],arr[low]);                  //
    return j;
    

    
}

void quickSort(vector<int> &arr, int low, int high){

    if(low<high){
        int pivotIndex = partition(arr,low,high);

        quickSort(arr, low,pivotIndex -1 );
        quickSort(arr, pivotIndex +1 , high);
    }
}

int main() {
    vector<int> arr={ 4,6,2,5,7,9,1,3};
    quickSort(arr, 0,arr.size() -1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}