#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }    
    }
    ans.push_back(temp);
}               

bool ifSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int i, j;
    // check left to the col
    for (int i = col; i >= 0; i--)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    // upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // lower diagnal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (ifSafe(i, col, board, n))
        {
            board[i][col] = 1;
            solve(col + 1, ans, board, n);
            board[i][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}
void printSolution(vector<vector<int>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j]==1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n = 6;
    vector<vector<int>> solution = nQueens(n);
     int i = 0;
     printSolution(solution,6);

    for(vector<int> x : solution) {
        cout << endl << "Possible Configuration [" <<++i << "] : "<<endl;
        for(int y : x) {
            cout << y << " ";
        }
    }
    return 0;
}