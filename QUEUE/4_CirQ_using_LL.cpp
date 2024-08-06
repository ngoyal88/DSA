#include <iostream>
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

class circularQ
{
public:
    Node *front;
    Node *rear;

    circularQ()
    {
        front = rear = NULL;
    }

    void enQ(int x)
    {
        Node *newnode = new Node(x);
        if (rear == NULL)
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = rear->next;
            rear->next = front;
        }
    }
    void deQ()
    {
        if (rear == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            free(temp);
        }
    }
    void get()
    {
        if (rear == NULL)
        cout<<"List is Empty"<<endl;

        else{
            cout<<"Front of Q is :"<<front->data<<endl;
            cout<<"Rear of Q is :"<<rear->data<<endl;
            cout<<"Front of Q is :"<<rear->next->data<<endl;
        }
    }
};
int main()
{
circularQ que;
que.enQ(10);
que.enQ(20);
que.enQ(30);
que.enQ(40);
que.deQ();
que.deQ();
que.deQ();
que.deQ();
que.get();
    return 0;
}