// creating two stacks in array

#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Overflow in stack 1" << endl; 
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if (top2 - top1  == 1)
        {
            cout << "Overflow in stack 2" << endl;
            
        }
        else
        {
            top2--;
            arr[top2] = data;
            
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2++;
        }
    }
    
    void print (){
        cout<<"top1 -> "<<top1<<endl;
        cout<<"top2 -> "<<top2<<endl;

        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
Stack st(10);
st.push1(1);
st.push1(2);
st.push1(3);
st.push1(4);
st.push1(5);
st.push2(6);
st.push2(7);
st.push2(8);
st.push2(9);
st.push2(10);
 
 st.print();


 



    return 0;
}