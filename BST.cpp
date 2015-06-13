//Binary search tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E>
{
private:
    BSTNode<Key,E>* root;
    int nodecount;

    //Private helper functions
    void clearhelp(BSTNode<Key,E>*);
    BSTNode<Key,E>* inserthelp(BSTNode<Key,E>*,
    				const Key&, const E&);
    BSTNode<Key,E>* deletemin(BSTNode<Key,E>*);
    BSTNode<Key,E>* getmin(BSTNode<Key,E>*);
    BSTNode<Key,E>* removehelp(BSTNode<Key,E>*, const Key&);
    E findhelp(BSTNode<Key,E>*, const Key&) const;
    void printhelp(BSTNode<Key,E>*, int) const;

public:
    BST() {root = NULL; nodecount = 0;}
    ~BST() {clearhelp(root);}

    void clear()
    {clearhelp(root); root = NULL; nodecount = 0;}

    //insert a record into the tree
    //k Key value of the record
    //e the record to insert
    void insert(const Key& k, const E& e)
    {
	root = inserthelp(root,k,e);
	nodecount++;
    }

    //remove a record from the tree
    //k Key value of the record to remove
    //return the record removed or NULL if there is none
    E remove(const Key& k)
    {
	E temp = findhelp(root,k);
	if (temp != NULL)
	{
	    root = removehelp(root,k);
	    nodecount--；
	}
	return temp;
    }

    //remove and return the root node from the dictionary
    //return the record removed, null if tree is empty
    E removeAny()
    {
	if (root != NULL)
	{
	    E temp = root->element();
	    root = removehelp(root, root->key());
	    nodecount--;
	    return temp;
	}
	else return NULL;
    }

    //return record with key value k, NULL if none exist
    //k the key value to find
    //return true if such exists, false otherwise. If
    //multiple records match "k", return an arbitrary one
    E find(const Key& k) const {return findHelp(root, k);}

    //return the number of records in the dictionary
    int size() {return nodecount；}

    void print() const
    {
	if (root == NULL) cout << "The BST is empty.\n";
	else printhelp(root,0);
    }
};


template <typename Key, typename E>
E BST<Key,E>::findhelp(BSTNode<Key,E>* root,
			const Key& k) const
{
    if (root == NULL) return NULL;
    if (k < root->key())
	return findhelp(root->left(),k);
    else if (k > root->key())
	return findhelp(root->right(),k);
    else return root->element();
}


template <typename Key, typename E>
BSTNode<Key, E>* BST<Key,E>::inserthelp(
	BSTNode<Key,E>* root, const Key& k,const E& it
{
    if (root == NULL)
	return new BSTNode<Key,E>(k,it,NULL,NULL);
    if (k < root->key(0)
	root->setLeft(inserthelp(root->left(),k,it));
    else root->setRight(inserthelp(root->right(),k,it));
    return root;
}


template <typename Key, typename E>
BSTNode<Key, E>* BST<Key,E>::
deletemin(BSTNode<Key,E>* rt)
{
    if (rt->left() == NULL)
	return rt->right();
    else
    {
	rt->setLeft(deletemin(rt->left()));
	return rt;
    }
}

template <typename Key, typename E>
BSTNode<Key,E>* BST<Key,E>::
getmin(BSTNode<Key,E>* rt)
{
    if (rt->left() == NULL)
	return rt;
    else return getmin(rt->left());
}

//remove a node with key value k
//return the tree with the node removed
template <typename Key, typename E>
BSTNode<Key,E>* BST<Key,E>::
removehelp(BSTNode<Key,E>* rt, const Key& k)
{
    if (rt == NULL) return NULL;
    else if (k< rt->key())
	rt->setLeft(removehelp(rt->left(),k));
    else if (k> rt->key())
	rt->setRight(removehelp(rt->right(),k));
    else
    {
	BSTNode<Key,E>* temp = rt;
	if (rt->left() == NULL)
	{
	    rt = rt->right();
	    delete temp;
	}
	else if (rt->right() == NULL)
	{
	    rt = rt->left();
	    delete temp;
	}
	else
	{
	    BSTNode<Key,E>* temo = getmin(rt->right());
	    rt->setElement(temp->element());
	    rt->setKey(temp->key());
	    rt->setRight(deletemin(rt->right()));
	    delete temp;
	}
    }
    return rt;
}

template <typename Key, typename E>
void BST<Key,E>::
clearhelp(BSTNode<Key,E>* root)
{
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

template <typename Key, typename E>
void BST<Key,E>::
printhelp(BSTNode<Key,E>* root, int level) const
{
    if (root == NULL) return;
    printhelp(root->left(),level+1);
    for (int i=0;i<level;i++)
	cout << "   ";
    cout << root->key() << "\n";
    printhelp(root->right(),level+1);
}
