#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertion_head(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertion_tail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertion_position(node *head, int data, int pos)
{
    node *temp = head;
    node *tmp = new node(data);
    int c = 0;

    while (c != pos-1)
    {
        temp = temp->next;
        c++;
    }
    tmp->prev = temp;
    tmp->next = temp->next;
    temp->next->prev = tmp;
    temp->next = tmp;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *NN = new node(10);
    node *head = NN;
    node *tail = NN;
    insertion_head(head, 12);
    insertion_tail(tail, 15);
    insertion_position(head,18,1);

    print(head);
    return 0;
}