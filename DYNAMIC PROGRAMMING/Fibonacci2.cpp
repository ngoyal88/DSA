//T.C O(n)
//S.C. O(1)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,prev1,prev2,curr;
    cout << "Enter no :";
    cin >> n;
    prev1 = 0;
    prev2 = 1;

    for (int i = 2; i < n + 1; i++)
    {
        curr = prev1 +prev2;
        prev1 = prev2;
        prev2 = curr;
    }
     cout<<curr<<endl;
    return 0;
}