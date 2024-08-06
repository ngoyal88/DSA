// Reverse Linked list in K groups

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

Node *kReverse(Node *&head, int k)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    Node *nxt = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    if (nxt != NULL)
    {
        head->next = kReverse(nxt, k);
    }
    return prev;
}
int main()
{
    Node *nod = new Node(5);
    Node *ans;
    Node *head = nod;
    Node *tail = nod;
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    print(head);
    ans = kReverse(head, 2);
    cout << "hi" << endl;
    print(ans);
    return 0;
}