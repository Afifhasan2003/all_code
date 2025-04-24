//brute force approach(straight forward but not efficient)
//time complexity  O(n^3)


#include<iostream>
using namespace std;
int main() {

    int arr[]={-1,4,7,-5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxSum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {   
            int sum=0;
            for (int k = i; k <= j; k++){
                sum=sum+arr[k];
            }
            maxSum=max(sum,maxSum);
        }
        
    }
    
     
    cout<<maxSum;

return 0;
}
