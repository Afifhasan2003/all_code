//subarray is a part of array without breaking it between the array
//for example arr[]={1,2,3,4,5}
//a sub array of arr[] can be {2,3,4}

#include<iostream>
using namespace std;
int main() {

    int arr[]={ 1,2,0,7,2};

    int n=sizeof(arr)/sizeof(arr[0]);   //sizeof function gives value of how many bytes does it take,
                            //so we have to devide it by the size of a singe int 
                        
        for (int i = 0; i < n; i++)
        {
            int sum=0;                     
            for (int j = i; j < n; j++)
            {
                sum=sum+arr[j];
                cout<<sum<<"\t";
            }
            cout<<"\n";
        }
        
    



return 0;
}
