#include <bits/stdc++.h>
using namespace std;

//top down approach
int rodCutting1(vector<int> &prices, vector<int> &dp,int n){
    if(dp[n]>-1) {return dp[n];}
    if(n==0) return 0;

    int mx=0;
    for (int i = 1; i <= n; i++)
    {
        mx=max(mx ,prices[i] + rodCutting1(prices,dp,n-i));
    }

    
    dp[n] = mx;
    return mx;
    
}

//bottom up approach
int rodCutting2(vector<int> &prices, vector<int> &dp, int n){
    
    if(n==0) return 0;
    dp[0]=0;
    for (int i = 1; i <=n; i++)
    {
        int mx=0;
        
        for (int j = 1; j <=i; j++)
        {
            mx=max(mx, dp[i-j] + prices[j]);

        }
        dp[i]=mx;
        
    }
    return dp[n];
    
}

int rodCutting3(vector<int> &prices, vector<int> &dp, int n, vector<int> &cut1){
    if(dp[n]>-1) {return dp[n];}
    if(n==0) return 0;

    int mx=0;
    for (int i = 1; i <= n; i++)
    {
        int keep=rodCutting3(prices,dp,n-i,cut1);
        if(mx < prices[i] + keep){
            mx= prices[i] + keep;
            cut1[n]=i;
        }
    }
    
    
    dp[n] = mx;
    return mx;
}




// bottom up with cut position
int rodCutting4(vector<int> &prices, vector<int> &dp, int n, vector<int> &cut){
    
    if(n==0) return 0;
    dp[0]=0;
    for (int i = 1; i <=n; i++)
    {
        int mx=0;
        
        for (int j = 1; j <=i; j++)
        {
            if(mx< prices[j] + dp[i-j]){
                mx=prices[j] + dp[i-j];
                cut[i]=j;
            }

        }
        
        dp[i]=mx;
        
    }

    cout<<cut[n]<<" "; //this is the first cut, then the rest will be cut according to that length, which not concerning us rn

    //if we want all the cuts
    int ct=n;
    cout<<"all the cuts are: ";
    while (ct>0)
    {
        cout<<cut[ct]<<" ";
        ct = ct - cut[ct];    //remaining length of rod
    }
    
    
    
    return dp[n];
    
}

int main() {
    
    vector<int> prices={0,1,5,8,9,10,12,17,20,24,30};
    int p = prices.size();
    int n=7;

    vector<int> cut1(n+1,0);
    vector<int> cut2(n+1,0);


    vector<int> dp1 (n+1,-1);
    vector<int> dp2 (n+1,-1);
    vector<int> dp3 (n+1,-1);
    vector<int> dp4 (n+1,-1);


    // cout<<"max profit is: "<<rodCutting1(prices,dp,n);
    cout<<"max profit is: "<<rodCutting3(prices,dp2,n,cut1)<<endl;
    
    

    int ct=n;
    while (ct>0)
    {
        cout<<cut1[ct]<<" ";
        ct=ct-cut1[ct];
    }
    


    // rodCutting4(prices,dp4,n,cut2);

    

    return 0;
}