#include<iostream>
using namespace std;



int main() {


     int arr[]={3,-4,5,4,-1,7,-8};
     
        int maxsum=INT_MIN,n=sizeof(arr)/sizeof(int);
        
        for (int i = 0; i <n; i++)
        {
            int sum=0;
            for (int j = i; j < n; j++)
            {   
                sum=sum+arr[j];
                maxsum=max(maxsum,sum);
            }
            
        }                           //time complexity n^2
        cout<<maxsum;

return 0;
}