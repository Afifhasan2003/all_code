#include<iostream>

using namespace std;

int linearSearch(int n, int arr[],int key);
int binarySearch(int n, int arr[],int key);         //this is work is the numbers organized from small to big
                                                    //but it will have less time complexity of

int main(){
    int n,key;
    
    cout<<"HOw many number: "; cin>>n;
    int arr[n];
    cout<<"Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter number that you want to find "; cin>>key;

    // int result=linearSearch(n,arr,key);
     int result=binarySearch(n,arr,key);


    if (result != -1)
    {
        cout<<"index number is "<<result;
    }
    else cout<<"Number is not present";
    
    


}
int linearSearch(int n, int arr[ ], int key){    // here O(n)

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key)
        {
            return i;
        }

    }
    return -1;

}
int binarySearch(int n, int arr[],int key){  //here O(log 2 based n)

    int s=0,e=n;

    while (s<=e)
    {
        // int mid=(s+e)/2;

            int mid = s + (e-s)/2;  //basically its the same .. but if s & e are really big numbers 
                                    // then mid might get over floaded by s+e 

        if (arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]>key)
        {
           e=mid-1;
        }
        else 
         s=mid+1;
    }
    return -1;

}