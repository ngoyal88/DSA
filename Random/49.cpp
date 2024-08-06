// circular linked list

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(){};
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Deleted value is :" << value << endl;
    }
};

void insert_node(node *&tail, int d, int value)
{
    if (tail == NULL)
    {
        node *new_node = new node(d);
        tail = new_node;
        new_node->next = new_node;
    }
    else
    {
        node *crun = tail;
        while (crun->data != value)
        {
            crun = crun->next;
        }
        node *temp = new node(d);
        temp->next = crun->next;
        crun->next = temp;
    }
}
void print_cll(node *&tail)
{
    node *temp = tail->next;
    cout << tail->data << " ";
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print(node *&tail)
{
    node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
}

void delete_cll(node *&tail, int value)
{
    cout<<"hi";
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;
        
        while (curr->data  != value)
        {

            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(curr==prev){
            tail=NULL;
        }
        else if(tail ==curr){
            tail=prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    node *new_node = new node(10);
    node *tail = new_node;
    insert_node(tail, 20, 10);
    insert_node(tail, 30, 20);
    insert_node(tail, 40, 30);
    insert_node(tail, 50, 40);
    print(tail);
    delete_cll(tail, 30);
    print(tail);

    return 0;
}