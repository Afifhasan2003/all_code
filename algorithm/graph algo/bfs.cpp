#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<vector<int>> &g, vector<string> &color, vector<int> &dis, vector<int> &prev, int st, int last)
{

    int n = g.size();

    color[st] = "gray";
    dis[st] = 0;

    queue<int> que;
    que.push(st);

    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[node][i] == 1 && color[i] == "white")
            {
                que.push(i);
                color[i] = "gray";
                dis[i] = dis[node] + 1;
                prev[i] = node;
            }
        }

        color[node] = "black";
    }
    if (dis[last] == INT_MAX)
    {
        cout << "There is no path from " << st << " to " << last << endl;
        return -1;
    }
    cout << "Distance from " << st << " to " << last << " is " << dis[last] << endl;
    return dis[last];
}

void printPath(vector<vector<int>> &g, int st, int target, vector<int> &prev)
{
    if (st == target)
    {
        cout << st << " ";
        return;
    }
    else if (prev[target] == -1)
    {
        cout << "no path";
    }
    else
    {
        printPath(g, st, prev[target], prev);
        cout << target << " ";
    }
}

bool hasCycle(vector<vector<int>> &g, int start)
{
    int n = g.size();
    vector<string> color(n, "white");
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(start);
    color[start] = "gray";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[node][i] == 1)
            {
                if (color[i] == "white")
                {
                    color[i] = "gray";
                    parent[i] = node;
                    q.push(i);
                }
                else if (i != parent[node])
                {
                    // Found a back-edge → cycle exists
                    return true;
                }
            }
        }
        color[node] = "black";
    }
    return false;
}


int main()
{

    vector<vector<int>> g = {
        // 0 1 2 3 4 5 6 7   <-- column indexes
        /*0*/ {0, 1, 0, 0, 0, 0, 0, 0}, // 0 -> 1, 4
        /*1*/ {1, 0, 1, 0, 0, 1, 0, 0}, // 1 -> 0, 2, 5
        /*2*/ {0, 1, 0, 0, 0, 0, 1, 0}, // 2 -> 1, 6
        /*3*/ {0, 0, 0, 0, 0, 0, 1, 1}, // 3 -> 6, 7
        /*4*/ {0, 0, 0, 0, 0, 0, 0, 0}, // 4 -> (no edges)
        /*5*/ {0, 1, 0, 0, 0, 0, 0, 0}, // 5 -> 1
        /*6*/ {0, 0, 1, 1, 0, 0, 0, 0}, // 6 -> 2, 3
        /*7*/ {0, 0, 0, 1, 0, 0, 0, 0}  // 7 -> 3
    };

    int n = g.size();
    vector<string> color(n, "white");
    vector<int> prev(n, -1);
    vector<int> dis(n, INT_MAX);

    minDistance(g, color, dis, prev, 1, 7);
    printPath(g, 1, 7, prev);

    // Reset arrays for second BFS
    color.assign(n, "white");
    prev.assign(n, -1);
    dis.assign(n, INT_MAX);
    minDistance(g, color, dis, prev, 0, 4);
    printPath(g, 0, 4, prev);
    return 0;
}