#include<iostream>
using namespace std;


    int recBins(int arr[], int key, int st, int en){
        
        if(st<=en)
        {
            int mid= st + (en-st)/2;
        if (arr[mid]==key)
        {
            return mid+1 ;
        }
        else if (arr[mid]<key)
        {
            return recBins(arr,key,mid+1,en);
        }
        else if (arr[mid]>key)
        {
            return recBins(arr,key,st, mid-1);
        }
        
        }
         return -1;
    }
int main() {


     int arr[]={2,4,6,7,8,12,15,18};
     int size=sizeof(arr)/sizeof(arr[1]);
     
    while (1)
    {
         int key ,st=0;
     cin>>key;
    cout<< recBins(arr,key,st,size-1 )<<endl;
    }
    

return 0;
}