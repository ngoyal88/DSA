// zig zag traversl in binary tree;

#include <iostream>
#include <vector>
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

vector<int> zig_zag(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);

    bool LeftToRight = true;
    int size = q.size();
    while (!q.empty())

    {
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            int index = LeftToRight ? i : size - i - 1;
            ans[index] = front->data;

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        LeftToRight = !LeftToRight;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    cout << size << endl;
    return result;
}
int main()
{
    node *tree = NULL;
    tree = create(tree);
    vector<int> v = zig_zag(tree);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

// tc  O(n)
// sc  O(n)