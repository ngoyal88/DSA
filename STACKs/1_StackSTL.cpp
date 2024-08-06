#include <iostream>
#include <stack>
using namespace std;

void print(stack<int>  & s)
{
    if (s.empty())
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Elements of stack are :" << endl;
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
}
int main(){
stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
print(st);
print(st);
    return 0;
}