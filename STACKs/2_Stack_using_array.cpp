#include <iostream>
#include <vector>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack() {}
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Overflow" << endl;
        }
    }

    void pop(void)
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    void gettop(void)
    {
        if (top == -1)
            cout << "Stack is empty" << endl;

        else
            cout << arr[top] << " is the element on top." << endl;
    }

    bool empty(void){
        if(top == -1)
        return true;

        else 
        return false;
    }

    void print(stack s){
        while(!s.empty()){
        s.gettop();
            s.top--;
        }
        cout<<endl;
    }
};
int main()
{
    stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    //st.push(60);
     st.print(st);
    return 0;
}