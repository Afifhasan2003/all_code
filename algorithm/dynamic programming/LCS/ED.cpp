//edit distance for converting y into x;

#include <bits/stdc++.h>
using namespace std;

//top down
int ed(string &x, string &y, int n,int m, int i, int j, vector<vector<int>> &dp, vector<vector<char>> &b){

    if(dp[i][j]>-1) return dp[i][j];


     if(i==0) {
        return  dp[0][j] = j;
     }
     if(j==0){
        return dp[i][0]=i;
    
     }

     if(x[i-1]==y[j-1]){
        dp[i][j] = ed(x,y,n,m,i-1,j-1,dp,b);
        b[i][j]='e';  //equal
        return dp[i][j];

     }

     else 
     {
        int sub= ed(x,y,n,m,i-1,j-1,dp,b)+1;
        int del= ed(x,y,n,m,i-1,j,dp,b) +1;
        int ins= ed(x,y,n,m,i,j-1,dp,b) +1;

        if(sub<=del && sub<=ins){
            dp[i][j]=sub;
            b[i][j] = 's';
            return dp[i][j];
        }
        else if (del<sub && del<=ins)
        {
            dp[i][j]=del;
            b[i][j]= 'd';
            return dp[i][j];
        }
        else{
            dp[i][j]=ins;
            b[i][j]='i';
            return dp[i][j];
        }

     }

     return dp[i][j];  //which are basically [n][m]
}



int main() {

    string x="cata", y="cut";
    int n=x.length(), m=y.length();


    //top down ex
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    vector<vector<char>> b1(n+1,vector<char>(m+1,' '));
    
    cout<<ed(x,y,n,m,n,m,dp1,b1)<<endl;
    return 0;
}