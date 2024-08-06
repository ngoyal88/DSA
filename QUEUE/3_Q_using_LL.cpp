#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
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

class Q
{
public:
    Node *front;
    Node *rear;
    int size;

    Q()
    {
        front = rear = NULL;
    }

    void enQ(int x)
    {
        Node *temp = new Node(x);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
            rear->next = NULL;
        }
    }

    void deQ(void)
    {
        if (front == rear && rear == NULL)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }

    void get()
    {
        Node *temp = front;
        if (temp == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else
        {
            cout << "Element on Front is :" << front->data << endl;
            cout << "Element on Front is :" << rear->data << endl;
        }
    }
};

int main()
{
    Q que;
    que.enQ(1);
    que.enQ(2);
    que.enQ(3);
    que.enQ(4);
    que.deQ();
    que.get();
    return 0;
}