#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> arr)
{
    int maxi = arr[0];
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)

            sum = 0;
    }
    return maxi;
}
int main()
{
   vector<int> vec = {   }
    return 0;
}