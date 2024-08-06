//T.C o(n)
//S.C. O(n)
#include <iostream>
#include <vector>
using namespace std;
int fibb(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    // step 1
    if (dp[n] != -1)
        return dp[n];
    // step 2
    dp[n] = fibb(n - 1,dp) + fibb(n - 2,dp);
    return dp[n];
}
int main()
{
    int n ;
    cout<<" Enter no :";
    cin>> n;
    vector<int> dp(n+1) ;
    for (int i = 0; i < n+1; i++)
    {
        dp[i]=-1;
    }
    cout<< fibb(n,dp)<<endl;

    return 0;
}