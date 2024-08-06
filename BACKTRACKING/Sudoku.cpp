
//time complexity O(9^m)
// where m is no of empty cells
//S.C O(1)
#include <iostream>
#include <vector>
using namespace std;

bool ifSafe(int row, int col, vector<vector<int>> board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }
        // col check
        if (board[i][col] == val)
        {
            return false;
        }
        // 3*3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (ifSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            // Backtraking
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
int main()
{
    vector<vector<int>> suduko = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(suduko);

    cout << "Solved Suduko : " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << suduko[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}