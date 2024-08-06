//print matrix in spring form
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> spring(vector<vector<int>> matrix)
{
    vector<int> ans;
    int count = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    int starting_row = 0;
    int starting_col = 0;
    int end_row = n - 1;
    int end_col = m - 1;
    int total = m * n;

    while (count < total)
    {
        for (int i = starting_col; i <= end_col; i++)
        {
            ans.push_back(matrix[starting_row][i]);
            count++;
        }
        starting_row++;

        for (int i = starting_row; i <= end_row; i++)
        {
            ans.push_back(matrix[i][end_col]);
            count++;
        }
        end_col--;

        for (int i = end_col; i >= starting_col; i--)
        {
            ans.push_back(matrix[end_row][i]);
            count++;
        }
         end_row--;

         for (int i = end_row; i >= starting_row; i--)
         {
            ans.push_back(matrix[i][starting_col]);
            count++;
         }
         starting_col++;
         
        
        
    }
    return ans;
}

int main()
{
    vector<vector<int>> input{
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    vector<int> output=spring(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
    return 0;
}