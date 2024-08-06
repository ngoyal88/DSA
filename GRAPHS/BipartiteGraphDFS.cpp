#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int col, vector<int> adj[], int color[])
{
    color[node] = col;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, !col, adj, color) == false)
            {
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isBipartite(V, adj);
    if (ans)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}