// square root
#include <iostream>
using namespace std;
int root(long long int n)
{
    long long int s = 0;
    long long int e = n - 1;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;

    while (s <= e)
    {
        if ((mid * mid) == n)
        {
            ans= mid;
            break;
        }
        else if ((mid * mid) < n)
        {
            ans =mid;
            s = mid + 1;
        }
        else if ((mid * mid) > n)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    cout << root(12);
    return 0;
}