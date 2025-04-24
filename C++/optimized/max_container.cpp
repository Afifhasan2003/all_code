#include<iostream>
using namespace std;


    int brute(int arr[] , int n){  //time complexity O(n^2) very bad 

          int vol, maxvol=0;
    for (int i = 0; i < n ; i++)

    {
        for (int j = i+1; j < n; j++)
        {
            vol= (j-i) * min(arr[i], arr[j]);
            maxvol=max(maxvol,vol);
        }
        
    }
    return maxvol;

    }


    int optimum(int arr[], int n){

        int i=0, j=n-1;  //first index and second index
        int maxVol=0,curValue=0, width;
        while (i<j)
        {
            width=j-i;
            curValue= width*min(arr[j],arr[i]);
            maxVol=max(maxVol,curValue);

            arr[i]<arr[j] ? i++: j--;
            
        }
        return maxVol;
    }

int main() {


     int height[]={ 1,8,6,2,5,4,8,3,9};
        //imagine they are sequential pillures .. which two make biggest volume
     int n= sizeof(height)/sizeof(height[1]);
    cout<<brute(height,n)<<endl;

    cout<<optimum(height,n)<<endl;


return 0;
}