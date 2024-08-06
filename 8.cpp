// Book Allocation

#include <iostream>
using namespace std;
bool ifpossible(int arr[], int n, int m, int mid)
{
    int pagesum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (pagesum  +arr[i] <= mid)
        {
            pagesum = pagesum + arr[i];
        }
        else
        {
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
        if (count > m)
        {
            return false;
        }
    }
    return true;
}
int book(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (ifpossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[4] = {10, 20, 30, 40};
    cout << book(arr, 4, 2);
    return 0;
}