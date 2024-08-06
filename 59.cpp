//given a string of lower case characters 
//print character thet are occuring most number of times 

#include<iostream>
#include<vector>
using namespace std;


int main()
{
    string s;
    char ch;
    int a;
    cin>>s;
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i]=0;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
      a=s[i]-97;
      arr[a]++;  
    }
    for (int i = 0; i < 26; i++)
    {
       ch=i+97;
       cout<<ch<<" "<<arr[i]<<endl;
    }
    
    
    return 0;
}
