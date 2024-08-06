// topological sort is only valid for Directed Acyclic Graph (DAG)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
        dfs(it,adj,vis,st);
        }
        
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }
    return ans;
}
int main()
{
    int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);
        for (int i = 0; i < N; i++)
        {
            cout<<res[i]<<" ";
        }
        
    return 0;
}