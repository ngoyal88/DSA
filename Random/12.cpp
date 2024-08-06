// Bubble Sort
#include <iostream>
#include <vector>
using namespace std;
vector<int> bubble(vector<int> arr)
{
    for (int i =  arr.size() ; i > 0; i-- )
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}
int main()
{
    vector<int> a{7, 6, 9,10,35, 2, 1};
    vector<int> b = bubble(a);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}