//largest common subsequence of two sting

#include <bits/stdc++.h>
using namespace std;

//top down
int lcs(string &x, string &y, int n, int m, int i,int j, vector<vector<int>> &dp,vector<vector<char>> &b){

    if(i==0 || j==0) return 0;
    if(dp[i][j]>-1) return dp[i][j];

    if(x[i-1]==y[j-1]){         //i,j are length, for i=1, index is zero 
        // dp[i][j] = dp[i-1][j-1]+1;
        dp[i][j] = lcs(x,y,n,m,i-1,j-1,dp,b) + 1;
        b[i][j]='c';
        return dp[i][j];

    }

    int i1j= lcs(x,y,n,m,i-1,j,dp,b);
    int ij1= lcs(x,y,n,m,i,j-1,dp,b);

    if (i1j>= ij1)
    {
        // dp[i][j] = dp[i-1][j];
        dp[i][j] = i1j;
        b[i][j]='u';

    }
    else{
        // dp[i][j] = dp[i][j-1];
        dp[i][j] = ij1;
        b[i][j]='l';
    }

    return dp[i][j];
    
}

void displaysub(string &x, string &y,vector<vector<int>> &dp, vector<vector<char>>& b, int i, int j, vector<char> &seq){

        if(i==0 || j==0) return;
    
        if(b[i][j]=='c') {
            displaysub(x,y,dp,b,i-1,j-1,seq);
            seq.push_back(x[i-1]);
        }
        else if (b[i][j]=='u')
        {
            displaysub(x,y,dp,b,i-1,j,seq);
        }
        else if(b[i][j]=='l'){
            displaysub(x,y,dp,b,i,j-1,seq);
        }
 
}


//bottom up
int lcs2(string &x, string &y, int n, int m, vector<vector<int>> &dp,vector<vector<char>> &b){


    for(int k=0;k<=n; k++) dp[k][0]=0;
    for(int k=0;k<=m; k++) dp[0][k]=0;

    for (int i = 1; i <=n; i++)
    {

        for (int j = 1; j <=m ; j++)
        {
            if(x[i-1]==y[j-1]){
             dp[i][j] = dp[i-1][j-1] + 1;
             b[i][j]='c';
            }

            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j]= dp[i-1][j];
                b[i][j] = 'u';
            }
            else{
                dp[i][j]= dp[i][j-1];
                b[i][j]='l';
            }

        }
        
    }

    return dp[n][m];
    
    
}

void displaysub2(string &x, string &y,vector<vector<int>> &dp2, vector<vector<char>>& b2, int i, int j, vector<char> &seq){

        if(i==0 || j==0) return;
    
        if(b2[i][j]=='c') {
            seq.push_back(x[i-1]);
            displaysub2(x,y,dp2,b2,i-1,j-1,seq);
        }
        else if (b2[i][j]=='u')
        {
            displaysub2(x,y,dp2,b2,i-1,j,seq);
        }
        else if(b2[i][j]=='l'){
            displaysub2(x,y,dp2,b2,i,j-1,seq);
        }

}




int main() {
    
    string str1 = "XMJYAUZXYABZCUAGT";
    string str2 = "MZJAWXUYZABXZCA";

    int n=str1.length() , m = str2.length();

    vector<vector<int>> dp1(n+1, vector<int>(m+1,-1));
   
    vector<vector<char>> b(n+1,vector<char>(m+1,' '));

    int ans = lcs(str1,str2,n,m,n,m,dp1,b);

    cout<<ans<<endl;

    vector<char> seq;
    displaysub(str1,str2,dp1,b,n,m,seq);
    
    for(char a:seq){
        cout<<a<<" ";
    }



    //for bottom up
    cout<<"bottom up process:"<<endl;

    vector<vector<int>> dp2(n+1, vector<int>(m+1));
    vector<vector<char>> b2(n+1,vector<char>(m+1,' '));
    vector<char> seq2;


    
    int ans2= lcs2(str1,str2,n,m,dp2,b2);
    cout<<"size is: "<<ans2<<endl;
    cout<<"seq is: ";
    displaysub2(str1,str2,dp2,b2,n,m,seq2);
    reverse(seq.begin(),seq.end());

    for(char a:seq2)
            cout<<a<<" ";

    

    return 0;
}