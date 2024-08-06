// using kahn algorithm
//  for topological sort using BFS
//  KAHN ALGORITHM
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isCyclic(int V, vector<int> adj[])
{
    int cnt = 0;
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
        cnt++;
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
    if (cnt == V)
        return false;
    return true;
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

    bool res = isCyclic(N, adj);
    if (res)
    {
        cout << "Yes Cycle exists";
    }
    else
    {
        cout << "No cycle exists";
    }

    return 0;
}