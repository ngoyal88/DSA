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
int height(node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool right = isbalanced(root->right);
    bool left = isbalanced(root->left);
    bool diff = abs(height(root->right) - height(root->left)) <= 1;

    if (right && left && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    node * root =NULL;
    root = create(root);

    if (isbalanced(root))
    {
    cout<<endl<<"Tree is Balanced :)";
    }
    else{
        cout<<endl<<"Tree is Unbalanced  :(";
    }
    
    return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 -1