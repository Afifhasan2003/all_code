#include<iostream>
using namespace std;


void prime_factorizaing(int n);

int main() {


     int n;
     cin>>n;

     prime_factorizaing(n);


return 0;
}
void prime_factorizaing(int n){

    int arr[100]={0};
    for (int i = 2; i <= n; i++)
    {    
        arr[i]=i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i]==i)
        {
            for (int j = i*i; j <=n; j+=i)
            {
                if (arr[j]==j)
                {
                    arr[j]=i;
                }
                
            }
            
        }
        
    }               //arr became  arr = [0, 0, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2].
    while (n!=1)
    {
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }                           // 12= 12/2 = 6=n  ->2
                                // 6/2=3 = n       ->3
       

}