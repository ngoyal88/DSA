//best case O(n)
//worst case O(n^2)
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int temp = v[i];
        for (; j >= 0; j--)
        {
            if (v[j] > temp)
            {
                // shift
                v[j + 1] = v[j];
            }
            else
            {
                break;
            }
        }
        v[j + 1] = temp;
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