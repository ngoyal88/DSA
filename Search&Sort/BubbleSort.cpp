//best case O(n)
//worst case O(n^2)
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> & v)
{
    int n = v.size();
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
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
   vector<int> v = {9, 8, 3, 2, 100, 5, 4};
    sort(v);
    print(v);
    return 0;
}