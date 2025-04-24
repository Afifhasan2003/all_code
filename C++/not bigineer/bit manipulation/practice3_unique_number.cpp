#include<iostream>
using namespace std;

int unique(int arr[],int n);
int main() {


     int n=7;
     int arr[]={ 2,4,5,2,5,8,4};
     cout<<unique(arr,n);


return 0;
}

int unique(int arr[],int n){

    int xorsum=0;
    for (int  i = 0; i < n; i++)
    {
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}