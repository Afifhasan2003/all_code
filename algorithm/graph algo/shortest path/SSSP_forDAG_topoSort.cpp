#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=ZUFQfFaU-8U watch from 5 minute if dont understand
void topoSort_usingDFS(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, 
        stack<int>&st){

    vis[node] = 1;
    for(auto it: adj[node]){
        int v = it.first;   //it = {destination, weight}
        if(vis[v]!=1){
            topoSort_usingDFS(v,adj,vis,st);
        }
    }

    //the idea is, when going deep is done, push the vertex, this way, the vertices that come first will be at the top of stack, 
        //and the vertices that come after the source, or at the bottom layers, they will enter the stack first. so the top iteam of the stack is likely to be the actual parent of the tree that was created by the dfs 
    st.push(node);
}

vector<int> SSSP_ofDAG(vector<vector<pair<int,int>>>& adj, int source){           //single source sorted path of directed acyclic graph
    int n = adj.size();  //number of vertices
    vector<int> vis(n,0);
    vector<int> dist(n,1e9);  
    dist[source] = 0;


    stack<int> st;
    for(int i = 0; i<n; i++)        //maybe all vertices are not found via a dfs
        if(vis[i] !=1)
            topoSort_usingDFS(i, adj, vis, st);

    //making the stack is done.


    //step 2
    while (!st.empty())
    {
        int u = st.top(); st.pop();

        for(auto it:adj[u]){
            int v = it.first;
            int wt = it.second;
            if( dist[u] !=1e9 && dist[u]+wt < dist[v]) 
                dist[v] = dist[u] + wt;
        }
    }
    return dist;
}

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({4,1});
    
    int source = 0;
    vector<int> dist = SSSP_ofDAG(adj, source);
    for (size_t i = 0; i < V; i++)
        cout<<source<<"->"<<i <<" = "<< dist[i]<<endl;
    
    

}