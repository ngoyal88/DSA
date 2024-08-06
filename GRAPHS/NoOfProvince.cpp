#include <iostream>
#include <vector>
using namespace std;
int count=0;
void dfs(int node, vector<int> adj[], int vis[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

int province(int V,vector<int> adj[]){
    int vis[V] = {0};
    int count =0;
    for(int i=0 ;i < V;i++){
        if(!vis[i]){
        count ++;
         dfs(i,adj,vis);
        }
    }
    return count;
}
//{ Driver Code Starts.
int main()
{
    int V = 6, E = 4;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = province(V,adj);
    cout << ans;
    return 0;
}