#include <bits/stdc++.h>
using namespace std;


int timee=0;


void do_a_dfs(vector<vector<int>> &g,int cur, vector<string>&color, vector<int>&prev, vector<int>&disco, vector<int>&fin){

    cout<<cur<<" ";
    int n=g.size();
    color[cur]="gray";
    timee++;
    disco[cur]=timee;
    for (int i = 0; i < n; i++)
    {
        if(g[cur][i]==1 && color[i]=="white"){
            do_a_dfs(g,i,color,prev,disco,fin);
        }
    }

    color[cur]="black";
    timee++;
    fin[cur]=timee;

}

void dfs(vector<vector<int>> &g){
    int n= g.size();
    vector<string> color(n,"white");
    vector<int> prev(n,-1);
    vector<int> discovered(n,-1);
    vector<int> finished(n,-1);

    for (int i = 0; i <n; i++)
    {
        if(color[i]=="white"){
           do_a_dfs(g,i,color,prev,discovered,finished);

        }
    }
    


}

void dfsUsingStack(vector<vector<int>> &g) {
    int n = g.size();
    vector<string> color(n, "white");

    for (int i = 0; i < n; i++) {
        if (color[i] == "white") {
            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int cur = st.top();

                if (color[cur] == "white") {
                    color[cur] = "gray";
                    cout << cur << " ";
                }

                bool found = false;
                for (int j = 0; j < n; j++) {
                    if (g[cur][j] == 1 && color[j] == "white") {
                        st.push(j);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    color[cur] = "black";
                    st.pop();
                }
            }
        }
    }
}

int main() {
    
      vector<vector<int>> g = {
//  {s,a,b,c,d,e,f,g}  <-- column indexes
    {0,1,0,1,1,0,0,0}, // s = 0
    {0,0,1,1,0,0,0,0}, // a = 1
    {1,0,0,0,0,0,0,0}, // b = 2
    {0,0,1,0,0,0,0,0}, // c = 3
    {0,0,0,1,0,1,0,0}, // d = 4
    {0,0,0,1,0,0,0,0}, // e = 5
    {0,0,0,0,1,1,0,1}, // f = 6
    {0,0,0,1,0,0,0,0}  // g = 7
};


    dfs(g);
    cout << endl;
    dfsUsingStack(g);

    return 0;
}