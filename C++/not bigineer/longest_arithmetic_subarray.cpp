//arithmetic subarray is a subarray which's each int has constant diffence between each
//for example { 2,5,8,11,14}  here is has differce of 3 

#include<iostream>
using namespace std;
int main() {


    int arr[]={10,7,4,6,8,10,12,14,11}; 
    int n=sizeof(arr)/sizeof(arr[0]);

    int ans=2;               //minimum length is 2
    int pre=arr[1]-arr[0];   //previous differnce
    int j=2;                 // arr[1]-arr[0] is first different.. we need to start from arr[2]
    int current=2 ;          //we will start counting from 2 (current length)

    while (j<n)
    {
        if (pre==arr[j] - arr[j-1])
        {
            current++;
        }
        else if (pre!=arr[j] - arr[j-1])
        {
            pre=arr[j] - arr[j-1];
            current=2;
        }
        j++;
        if (ans<current)
        {
            ans=current;
        }
        
    }
    cout<<ans;  

return 0;
}
