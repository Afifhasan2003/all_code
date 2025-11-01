//this code is from gpt
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // remove if directed graph
}

void bfs(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n";
}

void dfsRecursiveUtil(vector<vector<int>> &adj, int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfsRecursiveUtil(adj, neighbor, visited);
    }
}

void dfsRecursive(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS (Recursive): ";
    dfsRecursiveUtil(adj, start, visited);
    cout << "\n";
}

void dfsIterative(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    st.push(start);

    cout << "DFS (Iterative): ";
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Reverse order for same behavior as recursive DFS
            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (!visited[*it]) st.push(*it);
            }
        }
    }
    cout << "\n";
}

int main() {
    int V = 5; // number of vertices
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    bfs(adj, 0);
    dfsRecursive(adj, 0);
    dfsIterative(adj, 0);

    return 0;
}
