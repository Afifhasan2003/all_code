//https://codeforces.com/problemset/problem/2024/B

//not working

#include<bits/stdc++.h>
using namespace std;

    bool isvalid(int arr[], int n,int k,int mid){
        sort(arr,arr+n);
        int can=0 , press=0;

        for (int i = 0; i < n; i++)
        {
            
            press +=arr[i];
            if (press>mid)
            {
                return false;
            }
            

        }
        return true;



    }



int main() {

int t;cin>>t;
for (int z = 0; z < t; z++)
{
    
    int n,k; cin>>n>>k; 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int st=k , end=2*k+n;

    int ans=-1;
    while (st<=end)
    {
        int mid=st+ (end-st)/2;

        if (isvalid(arr,n,k,mid))
        {
            end=mid-1;
            ans=mid;
        }
        else {
            st=mid+1;
        }
        
    }
    
    

    cout<<ans;

}

     


return 0;
}