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

// bst to inorder
void bstToinorder(node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    bstToinorder(root->left, in);
    in.push_back(root->data);
    bstToinorder(root->left, in);
}
// merge two vectors in sorted way;
vector<int> mergearray(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
}

// inorder to bst
node *inordertoBST(vector<int> &in, int s, int e)
{
    if (s < e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(in[mid]);
    root->left = inordertoBST(in, s, mid - 1);
    root->right = inordertoBST(in, mid + 1, e);
    return root;
}

// merge bst
node *mergeBST(node *root1, node *root2)
{
    vector<int> a, b;
    bstToinorder(root1, a);
    bstToinorder(root2, b);
    vector<int> inorder = mergearray(a, b);

    return inordertoBST(inorder, 0, inorder.size() - 1);
}

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

void LevelOrderTraversal(node *root)
{
cout<<"Hi";
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
    node *root1 = take_input(root1);
    inorder_traversal(root1);
    cout<<endl;   
    node *root2 = take_input(root2);
    inorder_traversal(root2);
    cout<<endl;
    node * ans = mergeBST(root1 , root2);
    inorder_traversal(ans);

    return 0;
}