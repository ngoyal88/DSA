// numeric keypad problem

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
void solve(string input, int index, vector<string> &ans, string mapping[], string output)
{
    if (index >= input.length())
    {
        ans.push_back(output);
        return;
    }

    int number = input[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);

        solve(input, index + 1, ans, mapping, output);
        
        output.pop_back();
    }
}

vector<string> keypad(string input)
{
    string output;
    int index = 0;
    vector<string> ans;

    if (input.length() == 0)
    {
        return ans;
    }

    string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(input, index, ans, mapping, output);
    return ans;
}

int main()
{
    string digits ;
    cout<<"Enter no .";
    cin>>digits;
    vector<string> vec = keypad(digits);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<endl;
    }
    
    return 0;
}