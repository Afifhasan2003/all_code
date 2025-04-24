#include<iostream>
using namespace std;

void subsets(int arr[],int n);
int main() {
    int n=4;
    int arr[n]={2,3,4,5};
     
    subsets(arr,n);

return 0;
}

void subsets(int arr[],int n){
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1<<j))                         //for i=5= 101  ,j=2=10,, 1<<j=4=100  ,,i & 1<<j = 100 ~~ 3  
            {                                       // You need to kind of memorize this logic 
                cout<<arr[j]<<", ";
            }
            
        }cout<<endl;
        
    }
    
}