#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    
    int count=0;
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());
    int ss= s.size(); 
    int gs= g.size();

    int i=0, j=0;

    while (i<gs && j<ss)
    {
        if(g[i]<=s[j]){
            count++;
            i++;
            j++;
        }
        else{
            j++;
        }

    }
    
    
    
    return count;
}

int main() {
    
    vector<int> g={10,9,8,7};
    vector<int> s={5,6,7,8};

    cout<<findContentChildren(g,s)<<endl;

    return 0;
}