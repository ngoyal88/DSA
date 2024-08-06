// check palidrome

#include <iostream>
#include <string.h>
using namespace std;

bool palidrome(string str,int s)
{
    int e = str.size() - s - 1;
    if (s > e)

        return true;

    if (str[s] != str[e])
        
        return false;
    else
    palidrome (str,++s);
}
int main()
{
    string str="abbccbba";
    if(palidrome(str,0)){
        cout<<"YES !";
    }
    else
    cout<<"NO!!!";
    return 0;
}