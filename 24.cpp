//ways to climb stairs when u can take either 1 or 2 step
//solve using recursion 
//base case for this problem is when u are present below 0 step ,which is not possible so return zero
//another case is when u are present on ground and have to reach ground ,so jump on same step so possible ways are only one


#include<iostream>
using namespace std;

int climb (int n){
    if (n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    return climb(n-1)+climb(n-2);
}
int main()
{
    int n;
    cout<<"Enter no :";
    cin>>n;
    cout<<climb(n);
    
    return 0;
}