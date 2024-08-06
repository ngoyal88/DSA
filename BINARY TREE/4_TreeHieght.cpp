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
int main()
{
    node * nude  = NULL;
    nude = create(nude);
    int count = height(nude);
    cout<<endl<<"Hieght of BST is :"<<count<<endl;

    return 0;
}