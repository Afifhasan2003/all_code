//edit distance for converting string x to string y

#include <bits/stdc++.h>
using namespace std;

//top down
int ed(string &x, string &y, int n,int m, int i, int j, vector<vector<int>> &dp, vector<vector<char>> &b){

    if(dp[i][j]>-1) return dp[i][j];


     if(i==0) {
        return  dp[0][j] = j;
        b[i][j]='i';
     }
     if(j==0){
        return dp[i][0]=i;
        b[i][j]='d';
    
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

//bottom up(gpt)
int ed2(string &x, string &y, int n, int m, vector<vector<int>> &dp, vector<vector<char>> &b){
    for (int i = 0; i <=n; i++)
    {
        dp[i][0]=i;
        b[i][0]='d';
    }
    for (int j = 0; j <=m; j++)
    {
        dp[0][j]=j;
        b[0][j]='i';
    }
     for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
                b[i][j]='e';
            }
            else{
                int sub= dp[i-1][j-1]+1;
                int del= dp[i-1][j]+1;
                int ins= dp[i][j-1]+1;

                if(sub<=del && sub<=ins){
                    dp[i][j]=sub;
                    b[i][j]='s';
                }
                else if(del<sub && del<=ins){
                    dp[i][j]=del;
                    b[i][j]='d';
                }
                else{
                    dp[i][j]=ins;
                    b[i][j]='i';
                }
            }
        }
    }

    return dp[n][m];
}


void displaysub2(string &x, string &y,vector<vector<int>> &dp, vector<vector<char>>& b, int i, int j, vector<char> &seq){

        if(i==0 || j==0) return;
    
        if(b[i][j]=='e') {
            displaysub2(x,y,dp,b,i-1,j-1,seq);
            seq.push_back(x[i-1]);
        }
        else if (b[i][j]=='s')
        {
            displaysub2(x,y,dp,b,i-1,j-1,seq);
            seq.push_back(x[i-1]);
        }
        else if (b[i][j]=='d')
        {
            displaysub2(x,y,dp,b,i-1,j,seq);
        }
        else if(b[i][j]=='i'){
            displaysub2(x,y,dp,b,i,j-1,seq);
        }
 
}




int main() {

    string x="cata", y="cut";
    int n=x.length(), m=y.length();


    //top down ex
    cout<<"top down "<<endl;
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    vector<vector<char>> b1(n+1,vector<char>(m+1,' '));
    
    cout<<ed(x,y,n,m,n,m,dp1,b1)<<endl;
        vector<char> seq1;
    displaysub2(x,y,dp1,b1,n,m,seq1);    
    for(auto c:seq1) cout<<c;    
    cout<<endl;



    //bottom up ex
     cout<<"bottom up "<<endl;
    vector<vector<int>> dp2(n+1,vector<int>(m+1,-1));
    vector<vector<char>> b2(n+1,vector<char>(m+1,' '));
    cout<<ed2(x,y,n,m,dp2,b2)<<endl;    

     vector<char> seq;
    displaysub2(x,y,dp2,b2,n,m,seq);    
    for(auto c:seq) cout<<c;    


    return 0;
}