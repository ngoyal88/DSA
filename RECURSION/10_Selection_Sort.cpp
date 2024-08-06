// selection sort using recursion
#include <iostream>
using namespace std;
void sort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[0],arr[min]);

    sort(arr + 1, n - 1);
}
int main()
{
    int arr[5] = {5, 9, 1, 3, 7};
    sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}