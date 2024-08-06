// breadth first search
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

void preparedADJlist(unordered_map<int, list<int>> &adj, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, bool> visited, unordered_map<int, list<int>> adj, vector<int> ans, int i)
{

    queue<int> Q;
    Q.push(i);
    visited[i] = 1;

    while (Q.empty())
    {
        int frontnode = Q.front();
        Q.pop();

        ans.push_back(frontnode);
        for (auto i : adj[frontnode])
        {
            if (!visited[i])
            {
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    preparedADJlist(adj, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(visited, adj, ans, i);
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> pr = { {4,4},{0,1},{0,2},{1,2},{0,3}};

    vector<int> a = BFS(5, pr);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
