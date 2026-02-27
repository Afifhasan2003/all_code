#include <bits/stdc++.h>
using namespace std;

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

int main() {
    
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if(ds.isOnSameSet(3, 7))
        cout<<"Same\n";
    else
        cout<<"Not Same\n"; 

    ds.unionByRank(3, 7);
    if(ds.isOnSameSet(3, 7))
        cout<<"Same\n";
    else        cout<<"Not Same\n"; 



    return 0;
}