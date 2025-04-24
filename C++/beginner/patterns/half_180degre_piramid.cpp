#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"how many row:";
    cin>>n;
    

    for (int i = 1; i <=n; i++)
    {
        
        
            int m=n-i;
            for (int k = 1; k <= m; k++)
            {
                cout<<"   ";
            }
            for (int k = 1; k <= i; k++)
            {
                cout<<"  "<<i<<"";
              
            }
            
        
        cout<<endl;
    }
    


}