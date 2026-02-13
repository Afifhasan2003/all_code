#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstraList(int V, vector<vector<pair<int,int>>> &graph, int source) {
        //V = number of vertices, pair<adjNode, weight> , source = starting node


    vector<int> dist(V, INF);   //distance from source to each vertex, initialized with infinity (this is the dp array)

    priority_queue<pair<int,int>, //<distance, nodeNumber>
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;      //based on first element of pair(distance)

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        
        if (currentDist > dist[node]) continue;   
             // we dont update pq when we find better distance,so we may have some old entries in pq which are not relevant anymore, we skip those


        for (auto it : graph[node]) {

            int adjNode = it.first;
            int adjWeight = it.second;

            if (dist[node] + adjWeight < dist[adjNode]) {

                dist[adjNode] = dist[node] + adjWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "\nDijkstra using Adjacency List:\n";
    for (int i = 0; i < V; i++)
        cout << "0 -> " << i << " = " << dist[i] << endl;
}


void dijkstraMatrix(int V, vector<vector<int>> &matrix, int source) {

    vector<int> dist(V, INF);

    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currentDist > dist[node]) continue;
             // we dont update pq when we find better distance,so we may have some old entries in pq which are not relevant anymore, we skip those

        for (int adjNode = 0; adjNode < V; adjNode++) {

            // If edge exists
            if (matrix[node][adjNode] != 0) {

                int weight = matrix[node][adjNode];

                if (dist[node] + weight < dist[adjNode]) {

                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    cout << "\nDijkstra using Adjacency Matrix:\n";
    for (int i = 0; i < V; i++)
        cout << "0 -> " << i << " = " << dist[i] << endl;
}


int main() {

    int V = 5;
    int source = 0;

    /* --------- Adjacency List Representation --------- */
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});

    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});

    adj[2].push_back({4, 3});

    adj[3].push_back({4, 1});


    /* --------- Adjacency Matrix Representation --------- */
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    matrix[0][1] = 2;
    matrix[0][2] = 4;

    matrix[1][2] = 1;
    matrix[1][3] = 7;

    matrix[2][4] = 3;

    matrix[3][4] = 1;


    /* --------- Call Both Functions --------- */
    dijkstraList(V, adj, source);
    dijkstraMatrix(V, matrix, source);

    return 0;
}
