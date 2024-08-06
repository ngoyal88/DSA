// Common elements in 3 sorted array

#include <iostream>
#include <vector>
using namespace std;

vector<int> commonelements(int A[], int sizea, int B[], int sizeb, int C[], int sizec)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sizea && j < sizeb && k < sizec)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {

            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;

        else if (B[j] < C[k])
            j++;

        else
            k++;
    }
    return ans;
}
int main()
{
    int arr1[6] = {1, 5, 10, 20, 40, 80};
    int arr2[5] = {6, 7, 20, 80, 100};
    int arr3[8] = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> a = commonelements(arr1, 6, arr2, 5, arr3, 8);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}