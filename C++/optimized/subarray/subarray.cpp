#include<iostream>
using namespace std;



 //number of subarray = n*(n+1)/2

int main() {


     int arr[5]={1,2,3,4,5};

        for (int i = 0; i <5; i++)
        {
            for (int j = i; j < 5; j++)
            {
                for (int k = i; k <=j ; k++)
                {
                    cout<<arr[k];
                }
                cout<<" ";
            }
            cout<<endl;
        }
        

return 0;
}