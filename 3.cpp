// find the peak element

#include <iostream>
using namespace std;
int peak(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            end = mid-1;
        }
         else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
         {
             ans = mid;
         }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 6, 4, 3};
    cout << peak(arr1, 10);
    return 0;
}