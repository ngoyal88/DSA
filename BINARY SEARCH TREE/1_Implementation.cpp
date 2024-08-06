#include <iostream>
#include <queue>
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
node *insertBST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d >= root->data)
    {
        root->right = insertBST(root->right, d);
    }
    else if (d < root->data)
    {
        root->left = insertBST(root->left, d);
    }
    return root;
}
node *take_input(node *&root)
{
    int data;
    cout << "Enter Data:" << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
    return root;
}

void inorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void LevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

node *min(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *max(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node *deleteFromBST(node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {

        // 0 child
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // child on right
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // child on left
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->right != NULL && root->left != NULL)
        {
            int minval = min(root->right)->data;
            root->data = minval;
            root->right = deleteFromBST(root->right, minval);
            return root;
        }
    }
    // leftpart
    else if (val < root->data)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main()
{
    node *bst = NULL;
    bst = take_input(bst);
    inorder_traversal(bst);
    cout << endl
         << endl;
    deleteFromBST(bst, 19);
    LevelOrderTraversal(bst);
    return 0;
}
