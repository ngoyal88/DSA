//find the first and last occurence in a sorted array that contains duplicate elements
#include<iostream>
using namespace std;
int first(int arr[],int size,int key ){
int start =0;
int end=size-1;
int ans=-1;
int mid = start + (end-start)/2;
while(start<=end){
    if (key < arr[mid]){
            end=mid-1;
        }
        else if(key > arr[mid]){
            start=mid+1;
        }
        else if (key == arr[mid]){
          
            ans=mid;
            end = mid-1;
            
        }
        mid =start+ (end-start)/2;
}
return ans;
}

int last(int arr[],int size,int key ){
int start =0;
int end=size-1;
int ans =-1;
int mid = start + (end-start)/2;
while(start<=end){
    if (key < arr[mid]){
            end=mid-1;
        }
        else if(key > arr[mid]){
            start=mid+1;
        }
        else if (key == arr[mid]){
            ans=mid;
            start =mid +1;
        }
        mid =start+ (end-start)/2;
}
return ans;
}
int main()
{
    int array[10]={1,2,2,2,5,5,5,7,7,7};
    cout<<"Position of first occurence is "<<first(array,10,5)<<endl;
    cout<<"Position of last occurence is "<<last(array,10,5)<<endl;
    cout<<"Position of last occurence is "<<last(array,10,3)<<endl;
    return 0;
}