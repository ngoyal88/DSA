// reverse a string

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void reverse(string &a, int s)
{

    int e = a.size() - s - 1;
    if (s > e)
    {
        return;
    }

    swap(a[s], a[e]);
    s++;
    reverse(a, s);
}
int main()
{
    string a = "nikhil";
    reverse(a, 0);
    cout << a << endl;
    return 0;
}