//relax all edges V-1 times
 //

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;


/* =========================================================
     BELLMAN FORD USING EDGE LIST
   ========================================================= */
vector<int> bellmanFord_forEdgeList(int V, vector<vector<int>> &edges, int s){  
    // edges have list of {starting, ending, weight}

    vector<int> dist(V, INF);
    dist[s] = 0;

    // relax all edges V-1 times
    for (int i = 0; i < V-1; i++)
    {
        for(auto id : edges){
            int u = id[0],      // starting vertex
                v = id[1],      // ending vertex
                w = id[2];      // weight of u->v

            if(dist[u] != INF && dist[u] + w < dist[v])     //relaxing
                dist[v] = dist[u] + w;
        }
    }

    // to capture if there is negative weight cycle
    for(auto id : edges){
        int u = id[0],
            v = id[1],
            w = id[2];

        if(dist[u] != INF && dist[u] + w < dist[v])
            return {-1};    // negative cycle exists
    }

    return dist;
}



//previously we iterated through all edges, now we will iterate through edges of all vertices 
vector<int> bellmanFord_forAdjList(int V, vector<vector<pair<int,int>>> &adj, int s){
                                                      //pair<destination, weight>
    vector<int> dist(V, INF);
    dist[s] = 0;

    for(int i = 0; i < V-1; i++){   // number of iterations = V-1

        for(int u = 0; u < V; u++){     //on each iteration, check all vertices and relax their adjacent edges
            for(auto it : adj[u]){
                int v = it.first;      // destination
                int w = it.second;     // weight

                if(dist[u] != INF && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    for(int u = 0; u < V; u++){
        for(auto it : adj[u]){      //iterate through all edges of all vertices
            int v = it.first;
            int w = it.second;

            if(dist[u] != INF && dist[u] + w < dist[v])
                return {-1};
        }
    }

    return dist;
}   // Time Complexity: O(V*E) where V is number of vertices and E is number of edges(outer loop runs V-1 times and inner two loop runs E times in total for all vertices)




vector<int> bellmanFord_forMatrix(int V, vector<vector<int>> &matrix, int s){

    vector<int> dist(V, INF);
    dist[s] = 0;

    for(int i = 0; i < V-1; i++){
        for(int u = 0; u < V; u++){
            for(int v = 0; v < V; v++){

                if(matrix[u][v] != 0){     // if edge exists. here we can not have edge with weight 0
                    int w = matrix[u][v];

                    if(dist[u] != INF && dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }
            }
        }
    }

    // check negative cycle
    for(int u = 0; u < V; u++){
        for(int v = 0; v < V; v++){

            if(matrix[u][v] != 0){
                int w = matrix[u][v];

                if(dist[u] != INF && dist[u] + w < dist[v])
                    return {-1};
            }
        }
    }

    return dist;
}




int main(){

    int V = 5;
    int source = 0;

    /* --------- Edge List Representation --------- */
    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };

    /* --------- Adjacency List Representation --------- */
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({4,1});


    /* --------- Adjacency Matrix Representation --------- */
    vector<vector<int>> matrix(V, vector<int>(V,0));

    matrix[0][1] = 2;
    matrix[0][2] = 4;
    matrix[1][2] = 1;
    matrix[1][3] = 7;
    matrix[2][4] = 3;
    matrix[3][4] = 1;


    /* --------- Call All Three --------- */

    vector<int> ans1 = bellmanFord_forEdgeList(V, edges, source);
    vector<int> ans2 = bellmanFord_forAdjList(V, adj, source);
    vector<int> ans3 = bellmanFord_forMatrix(V, matrix, source);


    cout << "Edge List Result:\n";
    for(auto d : ans1) cout << d << " ";
    cout << "\n\n";

    cout << "Adjacency List Result:\n";
    for(auto d : ans2) cout << d << " ";
    cout << "\n\n";

    cout << "Adjacency Matrix Result:\n";
    for(auto d : ans3) cout << d << " ";
    cout << "\n";

    return 0;
}
