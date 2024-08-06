// binary search in 2d array

#include <iostream>
#include <vector>
using namespace std;

bool binsearch(vector<vector<int>> nums, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    int rowIndex = mid / nums.size();
    int colIndex = mid % nums[0].size();
    if (target > nums[nums.size()][nums[0].size()])
        return false;
    if (s > e)
        return false;

    if (nums[rowIndex][colIndex] == target)
    {
        return true;
    }
    else if (nums[rowIndex][colIndex] > target)
    {
        binsearch(nums, s, mid - 1, target);
    }
    else
    {
        binsearch(nums, mid + 1, e, target);
    }
    return false;
}
bool search(vector<vector<int>> nums, int target)
{

    int s = 0;
    int col = nums[0].size();
    int row = nums.size();
    int max = col * row;
    int e = max - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;

        if (nums[rowIndex][colIndex] == target)
        {
            return true;
        }

        else if (nums[rowIndex][colIndex] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return false;
}
int main()
{
    vector<vector<int>> vec = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 21, 21}};

    int s = 0;
    int col = vec[0].size();
    int row = vec.size();
    int max = col * row;
    int e = max - 1;
    if (binsearch(vec, s, e, 30))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}