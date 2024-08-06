// Time Complexity (2^n)
// Space Complexity
#include <iostream>
#include <vector>
using namespace std;
bool flag = 0;
void SubsetSum(int i, int n, int set[], int targetsum, vector<int> &subset)
{
    // found valid sum
    if (targetsum == 0)
    {
        flag = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }
    // reched end of array
    if (i == n)
    {
        return;
    }
    //not considering current elemet 
     SubsetSum(i+1,n,set,targetsum,subset);

     //when subset element is less than target sum 
     if (set[i] <= targetsum)
     {
        subset.push_back(set[i]);
        SubsetSum(i+1,n,set,targetsum-set[i],subset);
        subset.pop_back();
     }
     
}
int main()
{
    int set[] = { 1, 2, 1 };
    int sum = 3;
    int n = sizeof(set) / sizeof(set[0]);
    vector<int> subset;
    cout << "Output 1:" << endl;
    SubsetSum(0, n, set, sum, subset);
    cout << endl;
    flag = 0;
    // Test case 2
    int set2[] = { 3, 34, 4, 12, 5, 2 };
    int sum2 = 30;
    int n2 = sizeof(set) / sizeof(set[0]);
    vector<int> subset2;
    cout << "Output 2:" << endl;
    SubsetSum(0, n2, set2, sum2, subset2);
    if (!flag) {
        cout << "There is no such subset";
    }
 
    return 0;
}