//selection sort

#include<iostream>
#include<vector>
using namespace std;

 vector<int> sort(vector<int> vec )
{
    
for (int i = 0; i < vec.size() -1; i++)
{
    int min =i;
   for (int j = i+1; j < vec.size(); j++)
   {
      if (vec[j] < vec[min]){
        min =j;
      }
     
   }
     swap (vec[min],vec[i]);
   
}
return vec;
}
int main()
{
    vector<int> arr{1,7,8,5,6};
    vector<int> arr1 = sort(arr);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout<<arr1[i]<<endl;
    }
    
    return 0;
}