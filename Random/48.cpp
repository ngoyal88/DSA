// Doubly linked list

#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node() {}
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Deleted node with data  :" << value << endl;
    }
};

void print_node(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_head(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_tail(node *&tail, int d)
{
    node *temp = new node(d);
    temp->prev = tail;
    tail->next = temp;
    temp = tail;
}

void  linkedlist_length(node *&head)
{
    int len;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << len;
 
}

void insert_at_position(node *&head, node *&tail, int position, int d)
{

    node *temp = head;
    node *temp1 = NULL;
    node *nod = new node(d);
    int count = 1;
    if (position == 1)
    {
        insert_at_head(head, d);
        return;
    }
    while (count < position)
    {
        temp1 = temp;
        count++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insert_at_tail(head, d);
        return;
    }
    temp1->next = nod;
    nod->prev = temp1;
    nod->next = temp;
    temp->prev = nod;
}

void delete_node(node *&head, node *&tail, int position)
{
    
    int count = 1;
    node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *crun = head;
        node *prev = NULL;
        while (count < position)
        {
            prev = crun;
            crun = crun->next;
            count++;
        }
        if (temp->next == NULL)
        {
            tail = temp->prev;
            temp->prev->next = NULL;
            delete temp;
        }
        crun->prev = NULL;
        prev->next = crun->next;
        crun->next = NULL;

        delete crun;
    }
}

int main()
{
    node *nude = new node(32);
    node *head = nude;
    node *tail = nude;
    print_node(head);
    insert_at_head(head, 23);
    print_node(head);
    insert_at_tail(tail, 54);
    print_node(head);
    linkedlist_length(head);
    cout << endl;
    insert_at_position(head, tail, 2, 99);
    print_node(head);
    delete_node(head, tail, 5);
    print_node(head);
    return 0;
}
