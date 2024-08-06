//linear search
#include<iostream>
using namespace std;
int linear(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if(key==arr[i])
        {
            return i;
        }
    }
     
return -1;
}
int main()
{
    int ar[5]={1,2,3,4,5};
    cout<<linear(ar,5,5);
    return 0;
}