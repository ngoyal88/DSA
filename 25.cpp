//say number 

#include<iostream>
using namespace std;

void say(int n,string arr[]){ 

    if(n==0){
        return ;
    }

    int digit=n%10;
    n=n/10;
    say(n,arr);
    cout<<arr[digit]<<" | ";
}
int main()
{
    int n;
    cout<<"Enter no :";
    cin>>n;
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    say(n,arr);
    return 0;
} 