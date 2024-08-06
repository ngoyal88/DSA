// Doubly linked list

#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int count = 1;
    Node *temp = head;
    Node *temp1 = NULL;
    while (count < position)
    {
        temp1 = temp;
        temp = temp->next;
        count++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    // creating node to add

    Node *nod = new Node(d);
    //temp1->next = nod;
   // nod->prev = temp1;

    nod->next = temp;
    temp->prev = nod;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail,1, 7);
    print(head);
    return 0;
}