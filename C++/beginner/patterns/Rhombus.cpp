#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter row number:";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n-i; j++)
        {
            cout<<"   ";
        }
        for (int j = 0; j < n; j++)
        {
            cout<<" * ";
        }

            //we wont need this part

        // for (int j = 0; j < i-1; j++)
        // {
        //     cout<<"   ";
        // }
        
        cout<<endl;
    }

}