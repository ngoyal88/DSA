// binary search using recursion

#include <iostream>
using namespace std;
int search(int arr[], int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    if (s >= e)
        return 999999;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return search(arr, s, mid - 1, key);

    else
        return search(arr, mid + 1, e, key);
}
int main()
{
    int a[6] = {-1, 0, 3, 5, 9, 12};
    int ans = search(a, 0, 5, 9);
    if(ans == 999999)
        cout<<"Not Found !!";
    
    else 
    cout<<"Found at index :"<<ans<<endl;
    return 0;
}