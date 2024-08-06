// is sorted using recursion

#include <iostream>
using namespace std;
bool issorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
        return issorted(arr + 1, size - 1);
}
int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (issorted(a, 10))
    {
        cout << "yes";
    }
    else
        cout << "no";
    return 0;
}