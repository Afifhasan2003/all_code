#include<iostream>
using namespace std;





int main() {


     int arr[]={ 7,1,5,3,6,4};

     int maxprofit=0, bestBuy=arr[0];

     for (int i = 0; i < sizeof(arr)/sizeof(arr[1]) ; i++)
     {
        

        if(bestBuy<arr[i]){
            maxprofit=max(maxprofit,arr[i]-bestBuy);
        }

        bestBuy= min(bestBuy,arr[i]);


     }
        cout<<maxprofit;     


return 0;
}