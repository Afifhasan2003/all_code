#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

// Number of vertices (change as needed)
#define V 6

// ─────────────────────────────────────────
// BFS: finds a path from s to t in residual graph.
// Fills parent[] so we can trace the path back.
// Returns true if a path exists (Edmonds-Karp uses this).
// ─────────────────────────────────────────
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V] = {false};
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; v++) {
            // Visit v if not visited and residual capacity > 0
            if (!visited[v] && rGraph[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                if (v == t) return true;  // reached sink
                q.push(v);
            }
        }
    }
    return false;  // no path to sink
}

// ─────────────────────────────────────────
// DFS: finds ANY path from s to t in residual graph.
// Ford-Fulkerson uses this (not BFS).
// ─────────────────────────────────────────
bool dfs(int rGraph[V][V], int u, int t, bool visited[], int parent[]) { 
    visited[u] = true;
    if (u == t) return true;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[u][v] > 0) {
            parent[v] = u;
            if (dfs(rGraph, v, t, visited, parent))
                return true;
        }
    }
    return false;
}

// ─────────────────────────────────────────
// FORD-FULKERSON (uses DFS)
// Time complexity: O(E * |f*|)
// ─────────────────────────────────────────
int fordFulkerson(int graph[V][V], int s, int t) {
    int rGraph[V][V];  // residual graph
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int maxFlow = 0;
    int iter = 0;

    while (true) {
        bool visited[V] = {false};
        memset(parent, -1, sizeof(parent));     //memset is a C function to set all bytes of parent[] to -1 (indicating no parent)

        // Try to find an augmenting path via DFS
        if (!dfs(rGraph, s, t, visited, parent))
            break;  // no augmenting path → done

        iter++;

        // Find bottleneck (min residual capacity along path)
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // Print path
        cout << "Iteration " << iter << ": path = ";
        vector<int> path;
        for (int v = t; v != s; v = parent[v])
            path.push_back(v);
        path.push_back(s);
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << (i > 0 ? " -> " : "");
        cout << "  |  bottleneck = " << pathFlow << "\n";

        // Update residual graph
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;  // reduce forward edge
            rGraph[v][u] += pathFlow;  // increase backward edge (allows "undo")
        }

        maxFlow += pathFlow;
        cout << "  Flow so far = " << maxFlow << "\n";
    }

    cout << "\n[Ford-Fulkerson] Max flow = " << maxFlow
         << "  (iterations: " << iter << ")\n\n";
    return maxFlow;
}

// ─────────────────────────────────────────
// EDMONDS-KARP (uses BFS — guaranteed polynomial)
// Time complexity: O(V * E^2)
// ─────────────────────────────────────────
int edmondsKarp(int graph[V][V], int s, int t) {
    int rGraph[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int maxFlow = 0;
    int iter = 0;

    // Keep augmenting as long as BFS finds a path
    while (bfs(rGraph, s, t, parent)) {
        iter++;

        // Find bottleneck along the BFS path
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // Print path
        cout << "Iteration " << iter << ": path = ";
        vector<int> path;
        for (int v = t; v != s; v = parent[v])
            path.push_back(v);
        path.push_back(s);
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << (i > 0 ? " -> " : "");
        cout << "  |  bottleneck = " << pathFlow << "\n";

        // Update residual graph
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
        cout << "  Flow so far = " << maxFlow << "\n";
    }

    cout << "\n[Edmonds-Karp]  Max flow = " << maxFlow
         << "  (iterations: " << iter << ")\n\n";
    return maxFlow;
}

// ─────────────────────────────────────────
// MAIN — textbook example from slides
//
// Nodes: 0=s, 1=v1, 2=v2, 3=v3, 4=v4, 5=t
//
//        v1 --12--> v3
//       /|         /|\ 20
//     16 |10    9 7 |
//     /  v         v  \
//    s   v2 --14-> v4   t
//     \  ^         ^  /
//     13 |4         |4
//
// ─────────────────────────────────────────
int main() {
    // Capacity matrix  [u][v] = capacity of edge u->v
    int graph[V][V] = {
    //   s   v1  v2  v3  v4   t
        {0,  16, 13,  0,  0,  0},  // s
        {0,   0,  4, 12,  0,  0},  // v1
        {0,   0,  0,  0, 14,  0},  // v2
        {0,   0,  9,  0,  0, 20},  // v3
        {0,   0,  0,  7,  0,  4},  // v4
        {0,   0,  0,  0,  0,  0},  // t
    };

    int source = 0, sink = 5;

    cout << "=== Graph from slides: s=0, v1=1, v2=2, v3=3, v4=4, t=5 ===\n\n";

    cout << "--- Ford-Fulkerson (DFS) ---\n";
    fordFulkerson(graph, source, sink);

    cout << "--- Edmonds-Karp (BFS) ---\n";
    edmondsKarp(graph, source, sink);

    return 0;
}