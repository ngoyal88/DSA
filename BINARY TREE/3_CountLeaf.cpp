#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
void print_in(node *root, int &count)
{
    if (root == NULL)
        return;

    else
    {
        print_in(root->left, count);
        if (root->left == NULL && root->right == NULL)
        {
            count++;
        }

        print_in(root->right, count);
    }
}
node *create(node *root)
{
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data on the left of " << data << endl;
    root->left = create(root->left);

    cout << "Enter data on the right of " << data << endl;
    root->right = create(root->right);
}
int leaf(node *root)
{
    int count =0;
    print_in(root , count);
    return count;
}

int main()
{
    node *tree = NULL;
    tree = create(tree);
    int count = leaf(tree);
    cout<<endl<<"No of leaf nodes : "<<count<<endl;
    return 0;
}