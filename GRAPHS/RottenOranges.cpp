#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    //{r,c,t}
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    int countfresh =0 ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
            if(grid[i][j] == 1){
                countfresh++;
            }
                    
        }
        
    }
    int tm = 0;
    int delrow[] ={-1 ,0, +1, 0};
    int delcol[] ={0 ,+1, 0, -1};
    int count =0 ;
    while (!q.empty())
    { 
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow>= 0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
                count++;
            }  
        }
            
    }
if (countfresh != count)
{
    return -1;
}
return tm;
}

//{ Driver Code Starts.
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = orangesRotting(grid);
    cout << ans << "\n";
    return 0;
}
