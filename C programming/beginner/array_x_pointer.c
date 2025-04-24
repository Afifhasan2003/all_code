#include<stdio.h>

void ariya (int arr[], int n);

int main() {

    int arr[]= {5,6,7,8,9};
    ariya(arr , 5);
    return 0;

}
void ariya(int *arr, int n){

    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);

    
    }
    

}
