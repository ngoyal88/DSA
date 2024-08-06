// for topological sort using BFS
// KAHN ALGORITHM
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    queue<int> q;
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}
int main()
{
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topoSort(N, adj);
    for (int i = 0; i < N; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}