// bubble sort using recursion

#include <iostream>
#include <vector>
using namespace std;
void bubble(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubble(arr, n - 1);
}
int main()
{
    int arr[5]={5,6,3,7,1};
    bubble(arr,5);
    for (int i = 0; i < 5; i++)
    {
       cout<<arr[i]<<endl;
    }
    
    return 0;
}