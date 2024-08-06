// dynamic allocation of 2d array
#include <iostream>
using namespace std;

int main()
{ 
    //creating a 2d array
    int n;
    cout << "Enter no :";
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
       arr[i]=new int [4];
    }

    //taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cin>>arr[i][j];
        }
        
    }


    //giving output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    //releasing memory

    for (int i = 0; i < n; i++)
    {
        delete []arr[i];
    }
    delete []arr;
    
    return 0;
}