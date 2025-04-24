#include<iostream>
using namespace std;





int main() {


      int arr[]={3,-4,5,4,-1,7,-8};
      int sum=0, n=sizeof(arr)/sizeof(int), maxsum=INT_MIN;

        for (int  i = 0; i < n; i++)
        {
            sum=sum+arr[i];
            maxsum=max(maxsum,sum);
            if (sum<0)
            {
                sum=0;
            }
            
        }
        cout<<maxsum;


return 0;
}