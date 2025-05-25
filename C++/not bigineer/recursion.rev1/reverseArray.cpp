#include <bits/stdc++.h>
using namespace std;


void reverseArray(int *arr,int end,int start,int x){
   if(start<x/2) {
      swap(arr[end-1],arr[start]);
      reverseArray(arr,end-1,start+1, x);
}
}

int main() {
    
    int arr[] = {1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    reverseArray(arr,n,0,n);
    
    for(int i=0; i<n; i++) cout<<arr[i]<<"\t";
   return 0;
}