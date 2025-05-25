#include<iostream>
#include<climits>

using namespace std;

void swap_sorting(int n, int num[]){
    //put the biggest value at the last by swaping with adjecent number
    // Compare with the next numbers and slide the larger number to the right (ascending order)

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            // if (num[i]<num[j])  //descending
            if (num[i]>num[j])     //ascending
            {
                
                swap(num[i],num[j]);  
            }

            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

void selectionSorting(int n,int num[]){

    //everytime find the smallest value and put at the beginning
    for (int i = 0; i < n-1; i++){
        int minIndex=0;
        int minNum= INT_MAX;
        for (int j = i; j < n; j++)
        
            if (minNum>num[j]) {
                minIndex = j;
                minNum = num[j];
            }
        
        swap(num[minIndex],num[i]);
        
    }
    //selection sort is O(n^2) in all cases.
    //but if we add a flag to check if the array is already sorted, then it will be O(n) in best case.

    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    
}

void bubbleSorting(int n,int num[]){
    //put the biggest value at the last by swaping with adjecent number

    for (int i = n-1; i>=0 ; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i -1; j++)
        {
            if (num[j]>num[j+1])
            {
                swap(num[j],num[j+1]);
                didSwap = 1;
            }
            
        }
        if (didSwap == 0)       //**this would mean the array is already sorted. so no need to loop more
        {
            break;
        }
        
    }
    // bubble sort is O(n^2) in all cases.
    // but if we add a flag to check if the array is already sorted, then it will be O(n) in best case.

    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    
    
}

void insert_sorting(int n, int num[]){
        //find a place of a number by sliding the number to the left 

        for (int  i = 1; i <n; i++)    {
            
            int j=i;
            while (num[j-1]>num[j] && j>0 )
            {
                swap(num[j-1],num[j]);
                j--;
            }
            
            
        }
        for (int i = 0; i < n; i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<endl;
        //worst case is O(n^2),average is O(n^2) and best case is O(n) when the array is already sorted.
}

void recursiveBubbleSort(int n,int arr[]){
    if (n==1) return;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    recursiveBubbleSort(n-1,arr);
    
}

void recursiveInsertionSort(int a,int n,int arr[]){
    int m=n;
    if(n == a+1) return;
    while (m-- && m>0)
    {
        if(arr[m]<arr[m-1]){
            swap(arr[m],arr[m-1]);
        }
        else break;
    }
    recursiveInsertionSort(a,n+1,arr);
    
}

#include <algorithm> // for copy()

int main() {
    int original[] = {5, 2, 6, 1, 17, 4};
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[n], arr2[n], arr3[n], arr4[n] , arr5[n], arr6[n];
    copy(original, original + n, arr1);         // Copy original because sorting will change the array
    copy(original, original + n, arr2);
    copy(original, original + n, arr3);
    copy(original, original + n, arr4);
    copy(original, original + n, arr5);
    copy(original, original + n, arr6);

    cout << "Swap Sort: ";
    swap_sorting(n, arr1);

    cout << "Insertion Sort: ";
    insert_sorting(n, arr2);

    cout << "Bubble Sort: ";
    bubbleSorting(n, arr3);

    cout << "Selection Sort: ";
    selectionSorting(n, arr4);

    cout << "Recursive Bubble Sort: ";
    recursiveBubbleSort(n,arr5); for (int i = 0; i < n; i++) cout<<arr5[i]<<" ";  cout<<endl;

    cout<< "Recursive insertion sort: ";
    recursiveInsertionSort(n,0,arr6); for (int i = 0; i < n; i++) cout<<arr6[i]<<" ";


    return 0;
}
