// insert at the top element
// reverse a stck

#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }
    int topElement = st.top();
    st.pop();
    // recursive call
    insert_at_bottom(st, target);
    // backtracking
    st.push(topElement);
}

void ReverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int target = st.top();
    st.pop();

    ReverseStack(st);
    insert_at_bottom(st, target);
    
}

void PrintStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    // int target = s.top();
    // s.pop();
    // insert_at_bottom(s, target);
     ReverseStack(s);
    PrintStack(s);

    return 0;
}