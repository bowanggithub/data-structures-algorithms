template <typename Key, typename E>
E BPTree<Key,E>::findhelp(BPNode<Key,E>* rt, const Key k) const
{
    int currrec = binaryle(rt->keys(), rt->numrecs(), k);
    if (rt->isLeaf())
	if ((((BPLeaf<Key,E>*)rt)->keys())[currec] == k)
	    return ((BPLeaf<Key,E>*)rt)->recs(currec);
	else return NULL;
    else
	return findhelp((BPInternal<Key,E>*)rt->pointers(currec),k);
}



template <typename Key, typename E>
BPNode<Key,E>* BPTree<Key,E>::inserthelp(BPNode<Key,E>* rt,
			const Key& k, const E& e)
{
    if (rt->isLeaf())		//at leaf node, insert here
	return ((BPLeaf<Key,E>*)rt)->add(k,e);
    //add to internal node
    int currec = binaryle(rt->keys(), rt->numrecs(),k);
    BPNode<Key,E>* temp = inserthelp(
    	((BPInternal<Key,E>*)root)->pointers(currec(),k,e);
    if (temp != ((BPInternal<Key,E>*)rt)->pointers(currec))
	return ((BPInternal<Key,E>*)rt)->
			add(k,(BPInternal<Key,E>*)temp);
    else
	return rt;
}


/*delete a record with the given key value, and 
	return true if the root underflows */
template <typename Key,typename E>
bool BPTree<Key,E>::removehelp(BPNode<Key,E>* rt, const Key& k)
{
    int currec = binaryle(rt->keys(), rt->numrecs(), k);
    if (rt->isLeaf())
	if (((BPLeaf<Key,E>*)rt)->keys()[currec] == k)
	    return ((BPLeaf<Key,E>*)rt)->del(currec);
	else return false;
    else
	if (removehelp(((BPInternal<Key,E>*)rt)->pointers(currec),k))
	    //child will merge if necessary
	    return ((BPInternal<Key,E>*)rt)->underflow(currec);
	else return false;
}
