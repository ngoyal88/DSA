// calculating power
#include <iostream>
using namespace std;
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if(b==1){
        return a;
    }
    b--;
    return a * power(a, b);
}
int main()
{
    cout << power(5, 5);
    return 0;
}