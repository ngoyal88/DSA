// Reverse the linked list using recursion

#include <iostream>
#include <vector>
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

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

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

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void reverse(Node *&head, Node *&curr, Node *&prev)
{

    if (curr == NULL)
    {
        prev = head;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

void reverseLL(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
    print(head);
}
int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    insertAtPosition(tail, head, 2, 20);
    insertAtPosition(tail, head, 3, 30);
    insertAtPosition(tail, head, 4, 40);
    insertAtPosition(tail, head, 5, 50);
    insertAtPosition(tail, head, 6, 60);
    print(head);
    //cout << endl;

    reverseLL(head);
    

    return 0;
}
