// best case
// worst case
//  fastest among bubble ,selection ,insertion sort
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid,int e)
{
    
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    // coping first half
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[s+i];
    }
    // copying second half
    for (int j = 0; j < len2; j++)
    {
        second[j] = arr[mid+1+j];
    }
    // merge 2 sorted array

    int index1 = 0;
    int index2 = 0;
    int newI = s;

    while (index1 < len1 && index2 < len2)
    {
        if (second[index2] >= first[index1])
        {
            arr[newI] = first[index1++];
        }
        else
        {
            arr[newI] = second[index2++];
        }
        newI++;
    }
    while (index1 < len1)
    {
        arr[newI++] = first[index1++];
    }
    while (index1 < len1)
    {
        arr[newI++] = second[index2++];
    }
}
void mergeSort(vector<int> & array,  
               int const begin,  
               int const end) 
{ 
    // Returns recursively 
    if (begin >= end) 
        return;  
  
    auto mid = begin + (end - begin) / 2; 
    mergeSort(array, begin, mid); 
    mergeSort(array, mid + 1, end); 
    merge(array, begin, mid, end); 
} 
int main()
{
    vector<int> vec = {6, 7, 1, 2, 3, 4, 9};
    int start = 0;
    int end = 7;
    mergeSort(vec, start, end);
    for (int i = 0; i < 7; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}