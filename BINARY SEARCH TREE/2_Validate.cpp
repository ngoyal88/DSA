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
void intraversal(node *root, vector<int>  & inorder)
{

    if (root == NULL)
    {
        return ;
    }
    intraversal(root->left, inorder);
    inorder.push_back(root->data);
    intraversal(root->right, inorder);
}
bool isSorted(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++) 
    {
        if (vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

bool isValidBST(node *root)
{

    vector<int> bst ;
   intraversal(root, bst);
    return isSorted(bst);
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
int main()
{
    node *tree = create(tree);
    inorder_traversal(tree);
    if (isValidBST(tree))
    {
        cout << "True :)";
    }
    else
    {
        cout << "False :(";
    }
    return 0;
}