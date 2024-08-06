//detect cycle in undirected graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int src,vector<int> adj[] , int vis[]){
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode :adj[node])
        {
            if(!vis[adjacentNode]){
                vis[adjacentNode] =1;
                q.push({adjacentNode,node});
            }
            else if(parent != adjacentNode){
                return true;
            }
        }
        
    }
    return false;
}

bool isCycle(vector<int> adj[],int V)
{
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if(detect(i,adj,vis)){
                return true;
            }
        }
        
    }
    return false;
}

int main() {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = isCycle(adj,V);
        if (ans)
            cout << "Cycle Detected!";
        else
            cout << "Cycle Not Found!";
    
    return 0;
}
// } Driver Code Ends
