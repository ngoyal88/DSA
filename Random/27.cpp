// sum of array using recursion

#include <iostream>
using namespace std;
int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    int s = arr[0] + sum(arr+1, size-1);
    return s;
}
int main()
{
    int a[4] = {1, 2, 3, 4};
    cout << sum(a, 4);
    return 0;
}