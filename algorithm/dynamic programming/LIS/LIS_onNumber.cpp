//longest increasing subsequence

#include <bits/stdc++.h>
using namespace std;

//helper
int LCSTopDown(vector<int> &x, vector<int> &y, int n, int m, int i,int j, vector<vector<int>> &dp,vector<vector<char>> &b){

    if(i==0 || j==0) return 0;
    if(dp[i][j]>-1) return dp[i][j];

    if(x[i-1]==y[j-1]){         //i,j are length, for i=1, index is zero 
        // dp[i][j] = dp[i-1][j-1]+1;
        dp[i][j] = LCSTopDown(x,y,n,m,i-1,j-1,dp,b) + 1;
        b[i][j]='c';
        return dp[i][j];

    }

    int i1j= LCSTopDown(x,y,n,m,i-1,j,dp,b);
    int ij1= LCSTopDown(x,y,n,m,i,j-1,dp,b);

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
void displaysub( vector<int> &x, vector<int> &y, vector<vector<int>> &dp, vector<vector<char>>& b, int i, int j, vector<int> &seq){
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



void LISusingLCS( vector<int> &x, int n){    //actually this is LNDS (longest non-decresing)

    vector<int> y= x;
    sort(y.begin(), y.end());

    vector<vector<int>> dp1(n+1 , vector<int>(n+1 , -1) );
    vector<vector<char>> b(n+1 , vector<char>(n+1 ,' ') );

    vector<int> ans;
    LCSTopDown(x,y, n,n,n,n,dp1, b );
    displaysub(x,y,dp1,b,n,n,ans);  
    for(int c:ans) cout<<c<<" ";
}

//strictly increasing
void LISusingLCS2(vector<int> &x, int n) {
    vector<int> y = x;
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end()); 

    int m = y.size(); // Get the new actual length of y

    // Use m for columns and the j-parameter
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));
    vector<vector<char>> b(n + 1, vector<char>(m + 1, ' '));

    vector<int> ans;
    LCSTopDown(x, y, n, m, n, m, dp1, b); // Pass m here
    displaysub(x, y, dp1, b, n, m, ans);  // And here
    
    for(int c : ans) cout << c << " ";
}


//doesnt give the actual sequence, only length of LIS, but in nlogn time complexity
int modifiedLIS(vector<int> arr){  // nlogn approach
    vector<int> temp;
    temp.push_back(arr[0]);
    int n= arr.size();

    for(int i=1; i<n; i++){
        //if(arr[i]> temp.back()){   //for strictly increasing
        if(arr[i]>= temp.back()){    //for non-decreasing
            temp.push_back(arr[i]);
        }
        else{
            int ind= lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind]= arr[i];
        }
    }

    cout<<"LIS sequence is: ";
    for(int x: temp) cout<<x<<" ";
    cout<<endl;
    return temp.size();






}



int main() {
    
    vector<int> arr = {10,22,9,33,21,33,50,41,60,80};
    int n= arr.size();
    cout<< "LNDS sequences are: "; //longest non-decreasing sequence
    LISusingLCS(arr, n);
    cout<<endl;
    cout<< "LIS sequences are: ";
    LISusingLCS2(arr, n);
    cout<<endl;
    
    cout<<"Length of LIS using nlogn approach is: "<< modifiedLIS(arr)<<endl;
    
    

    return 0;
}