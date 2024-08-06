#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> bfsOfGraph (int V ,vector<int> adj[]){
    int vis[V] = {0};
    vis[0] =1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] =1;
                q.push(it);
            }
        }

    }
return bfs;
}

//gfg driver code 
int main() {
        int V=5, E=4;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> ans =bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    return 0;
}
// } Driver Code Ends