//aggresive cow problems .

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
bool ifpossible(vector<int> stalls,int cows,int k,int mid){
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; i < k; i++)
        {
            if((stalls[j]-stalls[i]) >= mid){
                   return true;
            }
        }
        
    }
  return false;  
}
int cow(vector<int> stalls,int cows ){
    int max =*max_element(stalls.begin(), stalls.end());
    int min =*min_element(stalls.begin(), stalls.end());
    int s=0;
    int ans=-1;
    int e= max-min;
    int mid = s+(e-s)/2;
    while(s<=e){
     if(ifpossible(stalls,cows,e,mid)){
        ans=mid;
        s=mid+1;
     } 
     else{
             e=mid-1;
     }
     mid = s+(e-s)/2;  
    }
    return ans;
}
int main()
{ 
    vector<int> s{4,2,1,3,6};
    cout<<cow(s,2);
    return 0;
}