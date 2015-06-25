//Find the record that matchs a given key value
template <typename Key, typename E>
E TTTree<Key,E>::
findhelp(TTNode<Key,E>* root, Key k) const
{
    if (root == NULL) return NULL;
    if (k == root->lkey) return root->lval;
    if (k == root->rkey) return root->rval;
    if (k < root->lkey)
	return findhelp(root->left,k);
    else if (root->rkey == EMPTYKEY)
	return findhelp(root->center,k);
    else if (k < root->rkey)
	return findhelp(root->center,k);
    else 
	return findhelp(root->right,k);
}

template <typename Key, typename E>
TTNode<Key,E>* TTTree<Key,E>::
inserthelp(TTNode<Key,E>* rt, const Key k, const E e)
{
    TTNode<Key,E>* retval;
    if (rt == NULL) //empty tree: create a leaf node
	return new TTNode<Key,E>(k,e,EMPTYKEY,NULL,NULL,NULL,NULL);
    
    if (rt->isLeaf())	//at leaf node: insert here
	return rt->add(new TTNode<Key,E>)(k,e,EMPTYKEY,NULL,
					NULL,NULL,NULL;)

    //add to internal node
    if (k < rt->lkey)
    {
	retval = inserthelp(rt->left,k,e);
	if (retval == rt->left) return rt;
	else return rt->add(retval);
    }
    else if ((rt->rkey == EMPTYKEY) || (k < rt->rkey))
    {
	retval = inserthelp(rt->center,k,e);
	if (retval == rt->center) return rt;
	else return rt->add(retval);
    }
    else
    {
	retval = inserthelp(rt->right,k,e);
	if (retval == rt->right) return rt;
	else return rt->add(retval);
    }
}
