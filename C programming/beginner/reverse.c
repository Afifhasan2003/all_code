#include<stdio.h>

void reverse(int arr[], int n);

int main(){

    int arr[]={1,2,3,4,5};
    reverse(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t",arr[i]);
    }
    


} 

void reverse(int arr[], int n) {

    for (int i = 0; i < n/2; i++)
    {
        // int firstvalue=arr[i];
        // int lastvalue=arr[n-1-i];

        // arr[i]=lastvalue;
        // arr[n-1-i]=firstvalue;  

            //OR

        int temp;
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    
}