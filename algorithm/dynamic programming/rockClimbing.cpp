#include <bits/stdc++.h>
using namespace std;

void getClimbingPath(vector<vector<int>> &rock, vector<vector<int>> &dp, int minInd){

    int height = rock.size();     
    int width = rock[0].size();  

    cout<<"path is: ";

    cout << rock[height-1][minInd-1] << " ";

    for (int i = height; i > 1; i--) 
    {
        int ans = INT_MAX;
        int best = minInd;

        for (int j = minInd - 1; j <= minInd + 1; j++){
            
            if(j < 1 || j > width) 
                continue; 

            if(ans > dp[i-1][j]){
                ans = dp[i-1][j];
                best = j;
            }
        }

        minInd = best;
        cout << rock[i-2][minInd-1] << " ";
    }
    cout<<endl;
}

//wont work correctly if two block have same danger value
void getClimbingPath2(vector<vector<int>> &dp,int index){



    int height = dp.size();     
    int width = dp[0].size();  

    int new_index=index;
    cout<<"path is: ";
    for(int i = height-1; i>=1;i--){
        if(dp[i-1][index-1]<=dp[i-1][index] && dp[i-1][index-1]<=dp[i-1][index+1]){
            new_index=index-1;
        }
        else if(dp[i-1][index]<=dp[i-1][index-1] && dp[i-1][index]<=dp[i-1][index+1]){
            new_index=index; 
        }
        else{
            new_index=index+1;
        }
    
        cout<<dp[i][index] - dp[i-1][new_index]<<" ";

        index=new_index;
    }
    cout<<endl;
}


int rockClimbing(vector<vector<int>> &rock){
    
    int height=rock.size(), 
        width = rock[0].size();


    vector<vector<int>> dp(height+1 ,vector<int>(width+2));

    for (int i = 0; i <=width; i++)
    {
        dp[0][i]=0;
    }

    for (int i = 1; i <=width; i++)
    {
        dp[1][i]=rock[0][i-1];
    }
    
    for (int i = 0; i <=height; i++)
    {
        dp[i][0]=INT_MAX;
        dp[i][width+1]=INT_MAX;
    }

    for (int i = 2; i <=height; i++)
    {
        for (int j = 1; j <=width; j++)
        {
            dp[i][j]=rock[i-1][j-1] +min(dp[i-1][j-1],min(dp[i-1][j], dp[i-1][j+1]));
        }
        
    }

    int ans=INT_MAX, ind=-1;
    for (int i = 1; i <=width; i++)
    {
        // cout<<dp[height][i]<<"  ";

        // ans=min(ans,dp[height][i]);
        if(dp[height][i]<ans){
            ans=dp[height][i];
            ind=i;
        }
        
    }
    
    getClimbingPath(rock,dp, ind);
    getClimbingPath2(dp, ind);

    return ans;
    

}



int main() {
    
    vector<vector<int>> rock={
        {3,2,5,4,8},
        {5,7,5,6,1},
        {4,4,6,2,3},
        {2,8,9,5,8}
        
       
    };

    int den=rockClimbing(rock);
    cout<<"min danger is:"<<den<<endl;

    
    return 0;
}