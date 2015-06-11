template <typename E>
void preorder(BinNode<E>* root)
{
    if (root == NULL) return;
    visit(root);
    preorder(root->left());
    preorder(root->right());
}


template <typename E>
void postorder(BinNode<E>* root)
{
    if (root == NULL) return;
    postorder(root->left());
    postorder(root->right());
    visit(root);
}


template <typename E>
void inorder(BinNode<E>* root)
{
    if (root == NULL) return;
    inorder(root->left());
    visit(root);
    inorder(root->right());
}
