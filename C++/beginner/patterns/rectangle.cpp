//creating a rectangle line shape

#include<iostream>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;


    for (int i = 1; i <= row ; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            
            
             if (j==1 || j==col || i==1 || i==row)
             {
                cout<<"*   ";
             } else cout<<"    ";   //both character number have to same including space(inside if & else)
                         
        }
        cout<<"\n";
    }
    

}