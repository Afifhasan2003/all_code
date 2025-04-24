//https://www.youtube.com/watch?v=srsFN5OHBgw&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=23


#include<bits/stdc++.h>
using namespace std;


    bool isvalid(int arr[],int n,int m,int mid){


        int men=1, time=0;

        for (int i = 0; i < n; i++)
        {
            if (time+arr[i] <= mid)
            {
                time +=arr[i];  
            }
            else
            {
                men++;
                time=arr[i];
            }
            
            
        }
        
        return men<=m;





    }


int main() {


     int arr[]={5,6,4,8};  //let these be length of pillar
     int n=sizeof(arr)/sizeof(arr[0]);
     int m=3;               //number of painter 

    //MINIMUM time to complete pointing all the pillar.. worker will work conteguously

    int st= *max_element(arr,arr+n);
    int end=0;
    for (int i = 0; i < n; i++)
    {
        end +=arr[i];
    }
    int ans=-1;

    while (st<=end)
    {
        int mid=st+ (end-st)/2;

        if (isvalid(arr,n,m,mid))
        {
            end=mid-1;  
            ans=mid;
        }
        else
        {
            st=mid+1;
        }

    }
    
    cout<<ans;
    

return 0;
}