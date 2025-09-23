#include<iostream>
using namespace std;
int main() {


     int n=5,m=5;
    int arr[5][5]={{1,  2,  3,   4, 5},
                   {6,  7,  8,   9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20},
                   {21, 22, 23, 24, 25}};

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)  //not from j=0 ,,else matrix will be transposed again
        {
            swap(arr[i][j],arr[j][i]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<"  ";
        }cout<<"\n";
        
    }
    


return 0;
}
