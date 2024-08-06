// quick sort
#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int count = 0;
    int pivot = arr[s];
    
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotindex = s + count;
    swap(arr[pivotindex], arr[s]);

    for (int i = s; i < pivotindex; i++)
    {
        for (int j = e; j > pivotindex; j--)
        {
            if (arr[i] > pivot && arr[j] < pivot)
                swap(arr[i], arr[j]);
        }
    }

    return pivotindex;
}

void quicksort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);

    quicksort(arr, p + 1, e);
}
int main()
{
    int arr[9] = {5, 3, 4, 6, 7, 9, 1, 2, 8};
    int n = 9;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}