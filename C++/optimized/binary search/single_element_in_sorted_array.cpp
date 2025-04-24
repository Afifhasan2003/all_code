//https://www.youtube.com/watch?v=qsbCBduIs40&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=21

#include<iostream>
using namespace std;





int main() {

                                               //each element twice except one
      int arr[]={1,1,3,4,4, 5 ,5,6,6,7,7};    //odd number in both side
//    int arr[]={1,1,2,2, 4 ,4,5,5,6};       //even number in both side
//   int arr[]={5};



        int st=0, end=sizeof(arr)/sizeof(arr[0])-1;
        // int x=1;
        if (!end)
        {
            cout<<"only element is= "<<arr[0];
            return 0;
        }
        if (arr[0] != arr[1])
        {
            cout<<arr[0]; return 0;
        }
        if (arr[end] !=arr[end-1])
        {
            cout<<arr[end];
            return 0;
        }
        

        while (st<=end)
        {
            int mid=st +(end-st)/2;
            if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
            {
                cout<<arr[mid]<<endl;
                return 0;
            }

            if (mid%2==0)
            {
                if (arr[mid]==arr[mid+1])
                {
                    st=mid+1;
                } 
                else{
                    end=mid-1;
                }
                
            }
            else
            {
                if (arr[mid]==arr[mid-1])
                {
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
                
            }
            
            
            





        }
        




    cout<<"no single element";

return 0;
}