// square root with precision 

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
double precision(long long int n,int pres,int tempsol){
    double ans =tempsol;
    double factor =1;
    factor =factor /10;

    for (int i = 0; i < pres; i++)
    {
        for (double j = ans; (j * j) < n; j =j+factor)
        {
            ans =j;
        }
        factor =factor /10;
        
    }
    return ans;

}
int main()
{
    cout << root(12)<<endl;
    cout<<precision(12,5,root(12));
    return 0;
}