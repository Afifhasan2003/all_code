#include<iostream>
using namespace std;





int main() {


     int arr[]={ 3,4,5,6,7,0,1,2};

     int st=0 ,  end= sizeof(arr)/sizeof(arr[0]) -1;

     int tar=6; //target


    while (st<=end)
    {
    
         int mid=st+ (end - st)/2;
            if (tar==arr[mid])
            {
                cout<<mid<<endl;
                return 0;
            }
            
        if (arr[st] < arr[mid])        //first half sorted
        {
            if (tar<arr[mid] && tar>=arr[st]) //target is in first sorted part
            {
                end=mid-1;
            }
            else {
                st=mid+1;
            }
        }
        else{                       //second half is sorted
            if (tar>arr[mid] && tar<=arr[end])
            {
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        

    }
    

    cout<<"not present";


return 0;
}