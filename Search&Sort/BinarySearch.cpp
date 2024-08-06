#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> arr, int key){
    int s = 0;
    int e = arr.size();
    int mid = e + ((s - e) / 2);
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = e + ((s - e) / 2);
    }
    return -1;
}
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 8, 9};
    if (search(v, 12) == 1)
    {
        cout << "Found :)";
    }
    else
    {
        cout << "Not found :(";
    }
    return 0;
}