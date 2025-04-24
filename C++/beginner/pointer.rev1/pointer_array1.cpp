#include<iostream>
using namespace std;
int main() {


     int arr[]={10,20,30,40};

     cout<<arr<<endl;   //address of first element! 
     cout<<*arr<<endl;  //first element

 
    int *ptr=arr;      //int *ptr;
                        //ptr=arr which means ptr=&arr[0]


    for (int i = 0; i < 4; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;

    //OR
    for (int i = 0; i < 4; i++)
    {
        cout<<*(arr+i)<<" ";     //can not do *arr++
    }
    




return 0;
}
