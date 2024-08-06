#include <iostream>
#include<vector>
using namespace std;

int firstocc(vector<int> nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int first = -1;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            first = mid;
            e = mid - 1;
        }
        else if (target < nums[mid])
            e = mid - 1;

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return first;
}

int lastocc(vector<int> nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int last = -1;
    while (s < e)
    {
        if (nums[mid] == target)
        {
            last = mid;
            s = mid + 1;
        }
        else if (target < nums[mid])
            e = mid - 1;

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    ans[0] = firstocc(nums, target);
    ans[1] = lastocc(nums, target);
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 2, 2, 3, 4, 5, 5, 6, 7};
    vector<int> a = searchRange(vec,2);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}