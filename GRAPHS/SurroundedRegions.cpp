#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> mat, vector<vector<int>> &vis)
{
    vis[row][col] =1;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row+delRow[i];
        int ncol = col+delCol[i];
        if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
            dfs(nrow,ncol,mat,vis);
        }       
    }
    
}

vector<vector<char>> fill(vector<vector<char>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (!vis[0][i] && mat[0][i] == 'O')
        {
            dfs(0, i, mat, vis);
        }
        if (!vis[n - 1][i] && mat[n - 1][i] == 'O')
        {
            dfs(n - 1, i, mat, vis);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, mat, vis);
        }
        if (!vis[i][n - 1] && mat[i][n - 1] == 'O')
        {
            dfs(i, n - 1, mat, vis);
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}

int main(){
        int n=5,m=4;
        vector<vector<char>> mat1 ={{'X', 'X', 'X', 'X'}, 
                                   {'X', 'O', 'X', 'X'}, 
                                   {'X', 'O', 'O', 'X'}, 
                                   {'X', 'O', 'X', 'X'}, 
                                   {'X', 'X', 'O', 'O'}};

        vector<vector<char>> mat2 ={{'X', 'O', 'X', 'X'}, 
                                    {'X', 'O', 'X', 'X'}, 
                                    {'X', 'O', 'O', 'X'}, 
                                    {'X', 'O', 'X', 'X'}, 
                                    {'X', 'X', 'O', 'O'}};
        
        vector<vector<char>> ans = fill(mat2);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    return 0;
}