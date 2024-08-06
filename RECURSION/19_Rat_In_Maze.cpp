// rat in amaze

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ispossible(int x, int y, vector<vector<int>> visited, vector<vector<int>> m, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && m[x][y]==1)
        return true;

    else
        return false;
}
void solve(vector<vector<int>> m, int n, vector<string> &ans, vector<vector<int>> visited, int x, int y, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // move down
    int newx = x + 1;
    int newy = y;
    if (ispossible(newx, newy, visited, m, n))
    {
        path.push_back('D');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }
    // move right
    newx = x;
    newy = y + 1;
    if (ispossible(newx, newy, visited, m, n))
    {
        path.push_back('R');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }
    // move up
    newx = x - 1;
    newy = y;
    if (ispossible(newx, newy, visited, m, n))
    {
        path.push_back('U');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }
    // move left
    newx = x;
    newy = y - 1;
    if (ispossible(newx, newy, visited, m, n))
    {
        path.push_back('L');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string> findpath(vector<vector<int>> m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    string path="";
    vector<vector<int>> visited =m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    solve(m, n, ans, visited, srcx, srcy, path);

    return ans;
}
int main()
{
    vector<vector<int>> maze;
    vector<string> paths;
    int n=4;
    maze[0]={1,1,0,1};
    //cout<<"Hello";
    maze[1]={0,1,1,0};
    maze[2]={1,1,1,0};
    maze[3]={0,0,1,1};
    paths = findpath(maze, n);
    for (int i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << endl;
    }

    return 0;
}