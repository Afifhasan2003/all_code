#include<iostream>
using namespace std;





int main() {


     int arr[]={ 0,2,3,9,7,5,4,1};   //peak element is 7 
                                    // peak can not be at the beginning or end

    int st=0 , end=sizeof(arr)/sizeof(arr[0])-1 ;

    while (st<=end)
    {
      int  mid=st+ (end-st)/2; 
      if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
      {
        cout<<mid<<endl;
        return 0;
      }
      if (arr[mid]> arr[mid-1])
      {
        st=mid+1;
      }
      if (arr[mid] > arr[mid+1])
      {
        end=mid-1;
      }
      

    }
    

    cout<<"no peak";

return 0;
}