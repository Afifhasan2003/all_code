#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// ===========================================================
// FLOYD WARSHALL WITH PATH RECONSTRUCTION
// ===========================================================
void floydWarshal(vector<vector<int>> &dist,
                  vector<vector<int>> &next,
                  vector<vector<int>> &last)
{
    int n = dist.size();

    for (int via = 0; via < n; via++)   // use all vertices as via
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // guard to prevent INF + INF overflow
                if (dist[i][via] != INF && dist[via][j] != INF &&
                    dist[i][j] > dist[i][via] + dist[via][j])
                {
                    dist[i][j] = dist[i][via] + dist[via][j];

                    // update path
                    next[i][j] = next[i][via];  // first step from i to j is first step from i to via
                    last[i][j] = last[via][j];  // last step before j is last step before j from via
                }
            }
        }
    }

    // check for negative cycle
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
            cout << "negative weight cycle exists\n";
    }
}

// ===========================================================
// PRINT PATH FROM u TO v (FORWARD USING NEXT MATRIX)
// ===========================================================
void printPathForward(int u, int v, vector<vector<int>> &next)
{
    if (next[u][v] == -1)
    {
        cout << "No path\n";
        return;
    }

    cout << "Forward Path: ";
    cout << u;

    while (u != v)
    {
        u = next[u][v];
        cout << " -> " << u;
    }

    cout << endl;
}


//this is the algorithm from the slide
void printPathBackward(int u, int v, vector<vector<int>> &last)
{
    if (last[u][v] == -1)
    {
        cout << "No path\n";
        return;
    }
    else if (last[u][v] == u)
    {
        cout << u << " -> " << v << endl;
        return;
    }
    else
    {
        printPathBackward(u, last[u][v], last);
        cout << " -> " << v;
        // note: the second recursive call is not needed
    }
}

int main()
{
    int V = 5;


    vector<vector<int>> matrix(V, vector<int>(V, INF));
    vector<vector<int>> next(V, vector<int>(V, -1));
    vector<vector<int>> last(V, vector<int>(V, -1));

    // initialize diagonal
    for (int i = 0; i < V; i++)
    {
        matrix[i][i] = 0;
        next[i][i] = i;
        last[i][i] = i;
    }

    matrix[0][1] = 2;
    matrix[0][2] = 4;
    matrix[1][2] = 1;
    matrix[1][3] = 7;
    matrix[2][4] = 3;
    matrix[3][4] = 1;

    // initialize next and last for direct edges
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] != INF && i != j)
            {
                next[i][j] = j;  // first step from i to j is j
                last[i][j] = i;  // last step before j is i
            }
        }
    }

    vector<vector<int>> dist = matrix;


    floydWarshal(dist, next, last);


    int source = 0, dest = 4;

    cout << "Distance " << source << " -> " << dest << " = " << dist[source][dest] << endl;
    printPathForward(source, dest, next);

    cout << "Distance " << source << " -> " << dest << " = " << dist[source][dest] << endl;
    cout << "Backward Path: ";
    printPathBackward(source, dest, last);
    cout << endl;

    return 0;
}
