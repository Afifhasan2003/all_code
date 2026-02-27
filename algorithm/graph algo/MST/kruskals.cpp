#include <bits/stdc++.h>
using namespace std;


//using disjoit data structure
class DisjointSet{
    vector<int> parent, rank;   //rank is basically size of the tree(subtree)
    public:
        DisjointSet(int n){     //constructor
            parent.resize(n+1);
            rank.resize(n+1);
            for (int i = 0; i <=n; i++)
            {
                parent[i]=i;    //at first, parent is it's self at the start
                rank[i] = 1;    // carrying just its self
            }    
        }

        int findTopParent(int node){
            if(node==parent[node])  //found parent
                return node;
            parent[node] = findTopParent(parent[node]);  //save the top parent as parent, coz thats what we need
            return parent[node];
        }

        void unionByRank(int u, int v){ //there is a edge from u to v
            int topParentOf_u = findTopParent(u);
            int topParentOf_v = findTopParent(v);

            if(topParentOf_u == topParentOf_v)  //their parent are same,  so loop exists
                return;

            if(rank[topParentOf_u] < rank[topParentOf_v]){  // tree that carry v is bigger
                parent[topParentOf_u] = topParentOf_v;  
                rank[topParentOf_v] += rank[topParentOf_u];
            }
            else{
                parent[topParentOf_v] = topParentOf_u;
                rank[topParentOf_u] += rank[topParentOf_v];
                }
        }

        bool isOnSameSet(int u, int v){
            return findTopParent(u) == findTopParent(v);
        }
};



int kruskal_mstWeight(vector<vector<int>> &G){
    //first make edge list  {weight, {u,v}}  = weight of edge from u to v
    vector<pair<int, pair<int,int>>> edges;
    int V = G.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = i+1; j < V; j++)
        {
            if(G[i][j] != 0){   //there is a edge from i to j
                int wt = G[i][j];
                edges.push_back({wt,{i,j}});
            }
        }
    }

    int mstWeight = 0;
    DisjointSet djset(V);
    sort(edges.begin(), edges.end()); // sort edges based on weight

    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(!djset.isOnSameSet(u,v)){
            mstWeight += wt;
            djset.unionByRank(u,v);
        }
    }
    
    return mstWeight;
}


int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Weight of the MST is = " << kruskal_mstWeight(graph);

    return 0;
}