template <typename Key, typename E>
class TTNode
{
public:
    E lval;			//left record
    Key lkey;			//left record's key
    E rval;			//right record
    Key rkey;			//right record's key
    TTNode* left;		//pointer to the left child
    TTNode* center;		//pointer to the middle child
    TTNode* right;		//pointer to the right child
    TTNode()
    {
	center = left = right = NULL;
	lkey = rkey = EMPTYKEY;
    }
    TTNode(Key lk, E lv, Key rk, E rv, TTNode<Key,E>* p1,
    		TTNode<Key,E>* p2, TTNode<Key,E>* p3)
    {
	lkey = lk; rkey = rk;
	lval = lv; rval = rv;
	left = p1; center = p2; right =p3;
    }
    ~TTNode() {}
    bool isLeaf() {return left == NULL;}
    TTNode<Key,E>* add(TTNode<Key,E>* it);
};

//add a new key/value pair to the node. There might be a 
//subtree associated with the record being added. This 
//information comes in the form of a 2-3 tree node with
//one key and a (possible NULL) subtree throught the
//center pointer field
template <typename Key, typename E>
TTNode<Key,E>* TTNode<Key,E>::add(TTNode<Key,E>* it)
{
    if (rkey == EMPTYKEY)	//only one key, insert here
    {
	if (lkey < it->lkey)
	{
	    rkey = it->lkey; rval = it->lval;
	    right = center; center = it->center;
	}
	else
	{
	    rkey = lkey;rval = lval; right = center;
	    lkey = it->lkey; lval = it->lval;
	    center = it->center;
	}
	return this;
    }
    else if (lkey >= it->lkey)
    {
	center = new TTNode<Key,E>(rkey, rval, EMPTYKEY,NULL,
				center, right,NULL);
        rkey = EMPTYKEY; rval = NULL; right = NULL;
	it->left = left; left = it;
	return this;
    }
    else if (rkey < it->lkey)
    {
	it->center = new TTNode<Key,E>(rkey,rval,EMPTYKEY,
				NULL, it->center, right,NULL);
	it->left = this;
	rkey = EMPTYKEY; rval = NULL; right =NULL;
	return it;
    }
    else
    {
	TTNode<Key,E>* N1 = new TTNode<Key,E>(rkey,rval,
				EMPTYKEY,NULL,this,it,NULL);
	it->left = right;
	right = NULL; rkey = EMPTYKEY; rval = NULL;
	return N1;
    }
}
