// stack and heap memory
// using heap memory using new opertor
//  heap memory returns pointer type i.e does not have name rather returns loction
// heap memory is to assign variable memory;

#include <iostream>
using namespace std;


int getsum(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}


int main()
{
    int n;
    cout << "Enter no of elements in a array : " << endl;
    cin >> n;
    int *a = new int[n];
    cout << "Enter elements of array;" << endl;
    ;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Sum :" << getsum(a, n);
    return 0;
}