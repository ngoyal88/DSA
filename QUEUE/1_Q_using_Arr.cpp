#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        if (rear == size)
        {
            cout << "Q is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (rear == front)
        {
            cout << "Q is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    bool isEmpty()
    {
        if (rear == front)
        {
            cout << "Q is empty" << endl;
            return true;
        }
        else
        {
            cout << "Q is FULL" << endl;
            return false;
        }
    }

    void fronnt()
    {
    cout<<"Element on Front is :"<<arr[front]<<endl;
    }
};
int main()
{
    Queue Hi(3);
    Hi.push(50);
    Hi.push(50);

    Hi.push(50);
    Hi.pop();
    Hi.pop();

    Hi.push(10);
    return 0;
}