#include <iostream>
#include <vector>
#include <limits.h>                                                  
using namespace std;

int solveRec(vector<int> &num, int x)
{
    // base case
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;
    
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans= solveRec(num,x-num[i]);
        if(ans!= INT_MAX){
            mini= min(mini,ans+1);
        }
    }
    
}
int main()
{
    return 0;
}