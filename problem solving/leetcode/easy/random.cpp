#include <bits/stdc++.h>
using namespace std;

void makezero(vector<vector<int>>& matrix,int row,int col, int a, int b){

    
    
        for (int i = 0; i < row; i++)
        {
            matrix[i][a]=0;
        }
        
        for (int i = 0; i < col; i++)
        {
            matrix[b][i]=0;
        }
        
        
    
    
}
void setZeroes(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col=matrix[0].size();

        int a,b;
        vector<pair<int,int>> zeroIndexex; 
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(matrix[i][j] ==0){
                    zeroIndexex.push_back({j,i});
                }
            }
            
        }

        for(auto [a,b]: zeroIndexex){
                    makezero(matrix,row,col,a,b);
        }


        
    }


int main() {
    
    vector<int> nums={0,3,7,2,5,8,4,0,6,1};
    // vector<int> nums={0,1,2,3,4,5,6,7};

    vector<vector<int>> mat={{ 0,1,2,0 },
                             { 3,4,5,2 },
                             { 1,3,1,5 }};

    int row=mat.size(), col=mat[0].size();

    setZeroes(mat);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}