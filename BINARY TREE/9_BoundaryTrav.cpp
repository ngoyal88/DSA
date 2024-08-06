// boundary traversal

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

void traversalLeft(node *root, vector<int> &ans)
{
    if ((root->left == NULL && root->right == NULL) || (root == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traversalLeft(root->left, ans);
    }
    else
    {
        traversalLeft(root->right, ans);
    }
}
void traversalLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if ((root->left == NULL && root->right == NULL))
    {
        ans.push_back(root->data);
    }
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}
void traversalRght(node *root, vector<int> &ans)
{
    if ((root->left == NULL && root->right == NULL) || (root == NULL))
    {
        return;
    }
    if (root->right)
    {
        traversalRght(root->right, ans);
    }
    else
    {
        traversalRght(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // for left part
    traversalLeft(root->left, ans);

    // for leaf nodes
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);

    // right in opposite manner
    traversalRght(root->right, ans);

    return ans;
}
int main()
{
    node *binary = NULL;
    binary = create(binary);
    vector<int> ans = boundary(binary);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}