//diameter and wigth of a tree are the same thing 
#include<iostream>
#include<vector>
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
int height (node *  root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;
}
int diameter (node * root)
{
    if(root == NULL)
    return 0;

    int op1  = diameter(root->left);
    int op2  = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(max(op1,op2) , op3);
    return ans;
}

int main()
{
    node * tree = NULL;
    tree = create(tree);
    int ans  = diameter(tree);
    cout<<endl<<"Diaameter of the tree is :"<<ans<<endl;
    return 0;
}