template <typename E>
int count(BinNode<E>* root)
{
    if (root == NULL) return 0;
    return 1 + count(root->left()) + count(root->right());
}
