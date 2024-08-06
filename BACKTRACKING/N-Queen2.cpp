#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> result;

bool isSafe(vector<vector<int>> board, int row, int col)
{
    int N = board.size();

    // checking left column
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    // upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    // lower left diagonal
    for (int i = row, j = col; j >= 0 && i < N; i++,j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board, int col)
{
    int N = board.size();
    if (col == N)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                {
                    v.push_back(j + 1);
                }
            }
        }
        result.push_back(v);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))

        {
            board[i][col] = 1;

            res = solve(board, col + 1) || res;

            board[i][col] = 0;
        }
    }
    return res;
}

vector<vector<int>> nQueen(int n)
{
    result.clear();
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0) == false)
    {
        return {};
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    int n = 4;
    vector<vector<int>> v = nQueen(n);

    for (int i = 0; i < result.size(); i++)
    {
        cout<<"[ ";
        for (int j = 0; j < n; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"]"<<endl;
        
    }
    
    return 0;
}