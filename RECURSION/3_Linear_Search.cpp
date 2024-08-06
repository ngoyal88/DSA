// linear search using recursion

#include <iostream>
using namespace std;
bool search(int arr[], int size, int key)
{
    if (size == 0)
        return false;
    
    if (key == arr[0])
        return true;
    else
    return search(arr + 1, size - 1, key);
}
int main()
{
    int a[5]={1,2,3,4,5};
    if(search (a,5,7))
    cout<<"Found";
    else
    cout<<"Not Found";
    return 0;
}