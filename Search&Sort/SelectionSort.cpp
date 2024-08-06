//best case O(n^2)
//worst case O(n^2)
#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        swap(v[min], v[i]);
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
    vector<int> v = {9, 8, 3, 2, 1, 5, 4};
    //cout << v.size() << endl;
    sort(v);
    print(v);
    return 0;
}