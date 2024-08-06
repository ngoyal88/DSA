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

pair<int, int> predessesorSuccesor(node *root, int key)
{

    int pre = -1;
    int suc = -1;
    node *temp = root;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            temp = temp->left;
            suc = temp->data;
        }
        else
        {
            temp = temp->right;
            pre = temp->data;
        }
    }

    node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pre, suc);
    return ans;
}
int main()
{
    node *bst = take_input(bst);
    pair<int, int> pr = predessesorSuccesor(bst, 10);
    cout << pr.first << " " << pr.second << endl;
    return 0;
}