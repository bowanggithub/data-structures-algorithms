template <typename Key, typename E>
bool checkBST(BSTNode<Key, E>* root, Key low, Key high)
{
    if (root == NULL) return true;
    Key rootkey = root->key();
    if ((root < low) || (rootkey > high))
	return false;
    if (!checkBST<Key, E>(root->left(),low,rootkey))
	return false;
    return checkBST<Key,E>(root->right(),rootkey,high);
}

