
// 15 10 8 12 16 25
#include <iostream>
#include <vector>
using namespace std;
// creation of node in binary seach tree

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

// insertion of node in binary search tree

node *insert(node *root, int d)
{
    node *temp = new node(d);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *cur;
        if (d <= root->data)
        {
            cur = insert(root->left, d);
            root->left = cur;
        }
        else
        {
            cur = insert(root->right, d);
            root->right = cur;
        }
    }
    return root;
}

// print inorder
void print_in(node *root)
{
    if (root == NULL)
        return;

    else
    {
        print_in(root->left);
        cout << root->data << " ";
        print_in(root->right);
    }
}

// print preorder
void print_pre(node *root)
{
    if (root == NULL)
        return;

    else
    {
        cout << root->data << " ";
        print_pre(root->left);
        print_pre(root->right);
    }
}

// print postorder
void print_post(node *root)
{
    if (root == NULL)
        return;

    else
    {
        print_post(root->left);
        print_post(root->right);
        cout << root->data << " ";
    }
}
void maximum(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    cout << "Maximum :" << root->data << endl;
}

void minimum(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << "Minimum :" << root->data << endl;
}

bool tree_search(node *root, int key)
{
    if (root == NULL)
        return false;
    else
    {
        if (root->data == key)
        {
            return true;
        }
        else if (key <= root->data)
        {
            tree_search(root->left, key);
        }
        else
        {
            tree_search(root->right, key);
        }
    }
}
int main()

{
    node *tree = new node(15);
    node *root = tree;
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);

    cout << "Pre-Order :";
    print_pre(root);
    cout << endl;
    cout << "In-Order :";
    print_in(root);
    cout << endl;
    cout << "Post-Order :";
    print_post(root);
    cout << endl;
    maximum(root);
    minimum(root);


    if(tree_search(root , 19)){
        cout<<"Found !"<<endl;
    }
    else
    cout<<"Not Found !"<<endl;
    return 0;
}
