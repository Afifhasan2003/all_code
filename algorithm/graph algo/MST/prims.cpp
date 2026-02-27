#include <bits/stdc++.h>
using namespace std;


// Prim's Algorithm to find the weight of the Minimum Spanning Tree (MST)
int weightOfMST(int v, vector<vector<int>> &G)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first weight, second node
    vector<int> visited(v, 0);
    pq.push({0, 0});

    int sum = 0;
    while ((!pq.empty()))
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (visited[node] == 1)
            continue;
        
         // not visited yet, take into mst

            visited[node] = 1;
            sum += wt;

            for (int i = 0; i < v; i++)
            {
                if (G[node][i] != 0)
                {
                    int adjNode = i;
                    int adjWeight = G[node][i];

                    if (visited[adjNode] != 1)
                    {
                        pq.push({adjWeight, i});
                    }
                }
            }
    }
    return sum;
}


// Prim's Algorithm to find the edges in the Minimum Spanning Tree (MST)`
vector<pair<int, int>> MST_Prim(int v, vector<vector<int>> &G)
{
    // (weight, node, parent)
    priority_queue
        <
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
        >
        pq;

    vector<int> visited(v, 0);
    vector<pair<int, int>> mst; // stores MST edges

    pq.push({0, 0, -1}); // start from node 0, no parent

    while (!pq.empty())
    {
        auto [wt, node, parent] = pq.top();
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = 1;

        // add edge to MST (skip first dummy node)
        if (parent != -1)
            mst.push_back({parent, node});

        // push adjacent edges
        for (int i = 0; i < v; i++)     //traverse all adjacent nodes of current node
        {
            if (G[node][i] != 0 && !visited[i])
            {
                pq.push({G[node][i], i, node});
            }
        }
    }

    return mst;
}

int main()
{

    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    cout << "value of mst is = " << weightOfMST(n, graph);

    cout << "\nEdges in the MST are:\n";
    vector<pair<int, int>> mstEdges = MST_Prim(n, graph);
    for (auto edge : mstEdges)
    
        cout << edge.first << " - " << edge.second << "\n";


    return 0;

}