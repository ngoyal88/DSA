#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Stack
{
public:
    Node *top;

    Stack()
    {

        top = NULL;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is UnderFlow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        free(temp);
    }
    void gettop()
    {
        Node *temp = top;
        if (temp == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else
        {

            cout << "Element on Top :" << temp->data << endl;
        }
    }
};
int main()
{
    Stack st;
    st.push(100);
    st.gettop();
    print(st.top);
    st.pop();
    st.gettop();
    return 0;
}