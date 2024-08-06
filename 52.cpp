//first repeating element in 1d array 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int first_repeated(vector<int> nums,int n){
    unordered_map<int,int> hash;
    for (int i = 0; i < n; i++)
    {
    hash[nums[i]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(hash[nums[i]]>1){
            return i+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vec ={1,5,2,3,5,3,4};
    int size=vec.size();
    cout<<first_repeated(vec,size);
    return 0;
}