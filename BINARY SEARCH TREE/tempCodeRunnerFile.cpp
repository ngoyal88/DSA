if(root == NULL)
    return true;

    else if (root->right->data > root->data || root->left->data < root->data )
    {
        return false;
    }
    validate(root->right);
    validate(root->left);