#include<iostream>
using namespace std;

    
    void prime(int m,int n);


int main() {
    int m,n;
    cin>>m>>n;
    prime(m,n);
        


return 0;
}  
    void prime(int m,int n){
        int arr[100]={0};   
        for (int  i = 2; i <= n; i++)
        {
            if (arr[i]==0)
            {
                for (int j =i*i ; j <=n; j=j+i)
                {
                    arr[j]=1;
                }
                
            }
            
        }
        for (int i = m; i <= n; i++)
        {
            if (arr[i]==0)
            {
                cout<<i<<" ";
            }
            
        }
        
        
    }
    