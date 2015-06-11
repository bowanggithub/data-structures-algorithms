template <typename E>
void preorder2(BinNode<E>* root)
{
    visit(root);
    if (root->left() != NULL) preorder2(root->left());
    if (root->right() != NULL) preorder2(root->right());
}
