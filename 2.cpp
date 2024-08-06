//binary search ---> only applicable to sorted data
#include<iostream>
using namespace std;
int binary(int arr[],int size,int key ){
    int start =0;
    int end= size-1;
    int ans =-1;
    int mid =start+ (end-start)/2;
    while(start<=end){
      
        if (key < arr[mid]){
            end=mid-1;
        }
        else if(key > arr[mid]){
            start=mid;
        }
        else if (key == arr[mid]){
            ans=mid;
        }
        mid =start+ (end-start)/2;
    }
 return ans;   
}
int main()
{
    int arr1[6]={1,2,3,4,5,6};
    cout<<binary(arr1,6,4);
    return 0;
}