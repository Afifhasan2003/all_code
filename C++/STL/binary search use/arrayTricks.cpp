#include<bits/stdc++.h>
using namespace std;

void checkElement(int arr[],int n,int a){
    bool present = binary_search(arr,arr+n,5);  //array has to be sorted

    if(present)printf("%d is present\n",a);
    else printf("%d is not present\n",a);
}

void lowBoundCheck(int arr[],int n,int a){
    int ind= lower_bound(arr,arr+n,a) - arr;    
    // This will give the index of the first element which is not less than a 
    //if not present it will give the index of the first element which is greater than a
    printf("position of %d is %d \n",a,ind);
}

void upperBoundCheck(int arr[],int n,int a){
    int ind= upper_bound(arr,arr+n,a) - arr;    
    // This will give the index of the first element which is greater than a 
    //if not present it will give the index of the first element which is greater than a
    printf("position of %d is %d \n",a,ind);
}
int main(){
    int arr[] = {2,3,5,6,7,11,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    checkElement(arr,n,5);
    lowBoundCheck(arr,n,5);
    upperBoundCheck(arr,n,5);
    
}