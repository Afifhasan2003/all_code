#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            
            cout<<" * ";
        }
       
        for (int j = 0; j <(2*n -2*i) ; j++)
        {
            cout<<"   ";
        }
        for (int j = 0; j < i; j++)
        {
             
            cout<<" * ";
        }
        cout<<endl;
        
        
    }
    
    for (int i = n; i <= n; i--)
    {
        for (int j = 0; j < i; j++)
        {
            
            cout<<" * ";
        }
       
        for (int j = 0; j <(2*n -2*i) ; j++)
        {
            cout<<"   ";
        }
        for (int j = 0; j < i; j++)
        {
            
            cout<<" * ";
        }
        cout<<endl;
        if (i==1)
        {
            break;
        }
        
        
    }
    


}