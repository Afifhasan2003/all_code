#include<iostream>
using namespace std;
int main() {


     int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
      
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)  //not from j=0 ,,else matrix will be transposed again
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<"\t";
        }cout<<"\n";
        
    }
    


return 0;
}
