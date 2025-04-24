//https://www.youtube.com/watch?v=7wOzDqsfXy0&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=24


#include<bits/stdc++.h>
using namespace std;

    bool isvalid(int arr[],int n,int m,int mid){

        int cow=1 , lastpos=arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i]-lastpos >= mid)
            {
                cow++;
                lastpos=arr[i];
            }
            if (cow==m)
            {
                return true;
            }
            
        }
        return false;



    }



int main() {


     int arr[]={1,2,8,4,9};        //co-ordinates of possible place in any line
     int n=sizeof(arr)/sizeof(arr[0]);
     int m=4;       //number of cows
     sort(arr, arr+n);

    int st=1; int end= *max_element(arr,arr+n) - *min_element(arr,arr+n);


    int ans=-1;
    while (st<=end)
    {
        int mid=st + (end-st)/2;

     if (isvalid(arr,n,m,mid))
     {
        st=mid+1;
        ans=mid;
     }
   
     else
     {
        end=mid-1;
     }
     
    }

    cout<<ans<<endl;



return 0;
}