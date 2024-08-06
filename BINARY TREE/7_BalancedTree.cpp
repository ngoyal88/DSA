// chech  whether tree is balanced or not  without using hieght
// function anf lower time of complexity

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



pair<bool, int> isbalancedfast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isbalancedfast(root->left);
    pair<bool, int> right = isbalancedfast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool diff = abs(right.second - left.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(right.second, left.second) + 1;

    if (rightans && leftans && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isbalanced(node *root)
{
    return isbalancedfast(root).first;
}

int main()
{
    node *root = NULL;
    root = create(root);

    if (isbalanced(root))
    {
        cout << endl
             << "Tree is Balanced :)";
    }
    else
    {
        cout << endl
             << "Tree is Unbalanced  :(";
    }

    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1