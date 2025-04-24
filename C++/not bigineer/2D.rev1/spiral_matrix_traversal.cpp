#include<iostream>
using namespace std;
int main() {


    //  #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //  #endif

    //OR

    // int arr[5][6]={{01,02,03,04,05,06},{18,19,20,21,22,07} and so on } 


     int n,m;
     cin>>n>>m;

     int arr[n][m];  //n=row number  m=column number

     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
     }

    int rowStart=0, rowEnd=n-1, columnStart=0, columnEnd=m-1;

    while (rowStart<=rowEnd && columnStart<=columnEnd)
    {
        //for rowstart
        for (int col = columnStart ; col <= columnEnd; col++)
        {
            cout<<arr[rowStart][col]<<" ";
           
        } rowStart++;

        //for columnEnd
        for (int row = rowStart ; row <= rowEnd  ; row++)
        {
            cout<<arr[row][columnEnd]<<" ";
            
        }columnEnd--;
        
        //for rowEnd
        for (int col =columnEnd; col >= columnStart; col--)   //not <=
        {
            cout<<arr[rowEnd][col]<<" ";
           
        } rowEnd--;

        //for columnStrt
        for(int row=rowEnd; row>=rowStart;row--){
            cout<<arr[row][columnStart]<<" ";
            
        }columnStart++;
        return 0;
        
    }
    


    


return 0;
}
