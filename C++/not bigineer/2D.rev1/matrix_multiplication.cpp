#include<iostream>
using namespace std;
int main() {


     #ifndef ONLINE_JUDGE
     freopen("input2.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif

    int n1,n2,n3;       //here dimention of the matrix are  n1*n2  and n2*n3 
      cin>>n1>>n2>>n3;

      int mat1[n1][n2], mat2[n2][n3] ,ansmat[n1][n3];

      for (int i = 0; i < n1; i++)
      {
        for (int j = 0; j < n2; j++)
        {
            cin>>mat1[i][j];
        }
        
      }
      for (int i = 0; i < n2; i++)
      {
        for (int j = 0; j < n3; j++)
        {
            cin>>mat2[i][j];
        }
        
      }
      for (int i = 0; i < n1; i++)  //initially each value of ansmat will be zero
      {
        for (int j = 0; j < n3; j++)
        {
            ansmat[i][j]=0;
        }
      }
      

        //multiplication starts

        for(int i=0; i<n1;i++){
            for(int j=0;j<n3;j++){
                for(int k=0;k<n2;k++){
                    ansmat[i][j] +=mat1[i][k]*mat2[k][j];
                }
            }
        }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ansmat[i][j]<<" ";
        }   
        cout<<endl;
    }

return 0;
}
