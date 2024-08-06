#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int count = 0;
    int pivot = arr[s];
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivoIndex = s + count;
    swap(arr[pivoIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivoIndex && j > pivoIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivoIndex && j > pivoIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivoIndex;
}
void quicksort(vector<int> &arr, int s, int e)
{

    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);

    quicksort(arr, p + 1, e);
}
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v = {2, 4, 1, 6, 9};
    int n = 5;
    quicksort(v, 0, 4);
    print(v);
    return 0;
}