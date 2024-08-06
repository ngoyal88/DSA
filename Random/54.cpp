// Wave print a matrix
#include <iostream>
#include <vector>
using namespace std;
void wave_print(vector<vector<int>> nums)
{
    int n = nums.size();
    int m = nums[0].size();
    for (int i = 0; i < n; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << nums[j][i] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << nums[j][i] << " ";
            }
        }
    }
}
int main()
{
    
    vector<vector<int>> vec = {
        {9, 10, 11, 12},
         {1, 2, 3, 4}, 
         {5, 6, 7, 8}, 
         {13, 14, 15, 16}};

    wave_print(vec);

    return 0;
}