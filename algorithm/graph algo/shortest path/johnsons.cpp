//didnt understand the algorithm, so i just copy paste the code from GPT
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// ==========================
// DIJKSTRA WITH PATH RECONSTRUCTION
// ==========================
void dijkstra(int src, const vector<vector<pair<int,int>>>& adj,
              vector<int>& dist, vector<int>& next, vector<int>& last)
{
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;

    next.assign(n, -1);
    last.assign(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;

        for(auto [v, w]: adj[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                next[v] = v;      // first step from u to v in Dijkstra
                last[v] = u;      // last step before v is u
            }
        }
    }
}

// ==========================
// BELL–FORD FOR JOHNSON (detect negative cycle)
// ==========================
bool bellmanFord(int s, vector<tuple<int,int,int>>& edges, vector<int>& h, int V)
{
    h.assign(V, INF);
    h[s] = 0;

    for(int i = 0; i < V-1; i++)
    {
        for(auto [u,v,w]: edges)
        {
            if(h[u] != INF && h[u] + w < h[v])
                h[v] = h[u] + w;
        }
    }

    // check negative cycle
    for(auto [u,v,w]: edges)
    {
        if(h[u] != INF && h[u] + w < h[v])
            return false;
    }

    return true;
}

// ==========================
// JOHNSON’S ALGORITHM
// ==========================
void johnson(int V, vector<tuple<int,int,int>>& edges)
{
    // Step 1: Add new vertex s = V, connect to all vertices with 0
    int newV = V+1;
    vector<tuple<int,int,int>> bfEdges = edges;
    for(int v = 0; v < V; v++)
        bfEdges.push_back({V, v, 0});

    vector<int> h;
    if(!bellmanFord(V, bfEdges, h, newV))
    {
        cout << "Negative weight cycle detected!\n";
        return;
    }

    // Step 2: Reweight edges
    vector<vector<pair<int,int>>> adj(V);
    for(auto [u,v,w]: edges)
    {
        int wPrime = w + h[u] - h[v];
        adj[u].push_back({v, wPrime});
    }

    // Step 3: Run Dijkstra from each vertex
    for(int u = 0; u < V; u++)
    {
        vector<int> dist, next, last;
        dijkstra(u, adj, dist, next, last);

        cout << "\nDistances from vertex " << u << ":\n";
        for(int v = 0; v < V; v++)
        {
            if(dist[v] == INF)
                cout << u << " -> " << v << " = INF\n";
            else
                cout << u << " -> " << v << " = " << dist[v] + h[v] - h[u] << endl;
        }

        // Optional: print path using next/last (can adapt your previous functions)
    }
}

int main()
{
    int V = 5;

    // Edge list: (u,v,weight)
    vector<tuple<int,int,int>> edges = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };

    johnson(V, edges);

    return 0;
}
