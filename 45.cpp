#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if ((x > 0 && x < n) && (y > 0 && y < n) && (visited[x][y] == 0) && m[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}

void solve(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited, vector<string> &ans, string path)
{
    if (x >= n - 1 && y >= n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    //  MOVE DOWN

    int newx = x + 1;
    int newy = y;
    if (issafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }
    //  MOVE UP

     newx = x - 1;
     newy = y;
    if (issafe(m, n, newx, newy, visited))
    {
        path.push_back('U');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }
    //  MOVE RIGHT

     newx = x;
     newy = y + 1;
    if (issafe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }
    //  MOVE LEFT

     newx = x;
     newy = y - 1;
    if (issafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string> findpath(vector<vector<int>> m, int n)
{
    string path="";
    vector<string> ans;
    int srcx;
    int srcy;
    cout<<"HEllo";
    vector<vector<int>> visited = m;
    if (m[0][0] == 0)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] == 0;
        }
    }

    solve(m, n, srcx, srcy, visited, ans, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> maze;
    int s;
    cout << "Enter no ::";
    cin >> s;
    cout << "Enter MAZE :: ";
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
           cin>>maze[i][j];
        }
    }
    cout<<"hell";
    vector<string> a=findpath(maze,s);
    for (int k = 0; k < a.size(); k++)
    {
        cout<<a[k]<<endl;
    }
    

    return 0;
}