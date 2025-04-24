#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter row number:";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }

            //we wont need this part

        // for (int j = 0; j < i-1; j++)
        // {
        //     cout<<"   ";
        // }
        
        cout<<endl;
    }

}