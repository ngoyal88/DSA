// implementation of circular quue using array

#include <iostream>
#include <vector>
using namespace std;

class circularQ
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    circularQ(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {

        // overflow
        if (front == (rear + 1) % size)
        {
            cout << "OVERFLOW" << endl;
        }

        else
        {
            rear++;
            rear = rear % size;
            arr[rear] = data;
            if (front == -1)
            {
                front = 0;
            }
        }
    }
    void pop(void)
    {
        // underflow
        if (front == rear && rear == -1)
        {
            cout << "UNDERFLOW" << endl;
        }
        // case when front is not 0 index
        else
        {
            arr[front] = -1;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
                front = front % size;
            }
        }
    }

    void isfront()
    {
        if (front == rear && rear == -1)
        {
            cout << "UNDERFLOW" << endl;
        }
        else
        cout << "Element at front is :" << arr[front] << endl;
    }
};
int main()
{
    circularQ hello(5);
    hello.push(5);
    hello.push(4);
    hello.push(3);
    hello.push(2);
    hello.push(1);
    hello.isfront();
    hello.pop();
    hello.isfront();
    hello.pop();
    hello.isfront();
    hello.pop();
    hello.isfront();
    hello.pop();
    hello.isfront();
    hello.pop();
    return 0;
}