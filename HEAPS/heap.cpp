// implementation
// insertion
// deletion
// heapsort
// heapify
#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int n)
    {
        size = size + 1;
        int index = size;
        arr[index] = n;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "Nothing present" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[leftindex] > arr[i])
            {
                swap(arr[leftindex], arr[i]);
                i = leftindex;
            }
            else if (rightindex < size && arr[rightindex] > arr[i])
            {
                swap(arr[rightindex], arr[i]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};

// heapify
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort
void heapsort(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, n, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(70);
    h.deletefromheap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creatiion

    for (int i = 1; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    heapsort(arr, 5);

    cout << endl;
    for (int i = 1; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}