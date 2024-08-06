//power of 2

#include<iostream>
#include<math.h>
using namespace std;

int power(int n){
    if(n==0){
        return 1;
    }
    return 2*power(n-1);
}
int main()
{
    int a;
    cout<<"Enter no :";
    cin>>a;
    cout<<power(a);
    return 0;
}