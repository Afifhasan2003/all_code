#include<stdio.h>

int count(int arr[], int n);
int main(){

    int arr[]={ 5,11,7,3,9};
    printf("Number of Odd number is :%d ", count( arr, 5));
    
} 

int count( int arr[], int n){
    int counter=0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] %2 !=0)
        {
            counter ++;
        }
    }
    
    return counter;
}