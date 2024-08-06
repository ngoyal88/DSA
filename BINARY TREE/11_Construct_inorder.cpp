// Given 2 array OF Inorder and Preorder
#include <iostream>
#include <vector>
#include<queue>
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
int findPosition(vector<int> in, int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
        return -1;
}
node *solve(vector<int> in, vector<int> pre, int & index, int inorderStart, int inorderEnd, int n)
{
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }
    int element = pre[index++];
    node *root = new node(element);
    int position = findPosition(in, element, n);

    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}
node *buildTree(vector<int> in, vector<int> pre, int n)
{
    int preOrderIndex = 0;
    node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
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
int main()
{
    vector<int> inorder = {4,2,5,1,6,3,7};
    vector<int> preorder = { 1,2,4,5,3,6,7};
    node * tree = buildTree(inorder , preorder ,7 );
    LevelOrderTraversal(tree);

}