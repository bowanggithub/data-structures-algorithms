E find(const Key& k) const
{
    SkipNode<Key,E> *x = head;		//dummy head node    
    for (int i=level; i>=0;i--)
	while ((x->forward[i] != NULL)&&(k>x->forward[i]->k))
	    x = x->forward[i];
    x = x->forward[0];
    if ((x!=NULL)&&(k==x->k)) return x->it;
    return NULL;
}

void insert(const Key& k, const E& it)
{
    int i;
    SkipNode<Key,E> *x = head;
    int newLevel = randomLevel();
    if (newLevel > level)	//new node is deapest in list
    {
	AdjustHead(newLevel);	//add null pointer to header
	level = newLevel;
    }
    SkipNode<Key,E>* update[level+1];
    for (i=level; i>=0; i--)	//search for insert position
    {
	while ((x->forward[i] != NULL)&& (x->forward[i]->k <k))
	    x = x->forward[i];
	update[i] =x;
    }
    x = new SkipNode<Key,E>(k,it,newLevel);
    for (i=0; i<=newLevel; i++)
    {
	x->forward[i] = update[i]->forward[i];
	update[i]->forward[i] = x;
    }
}

//pick a level using an exponential distribution
int randomLevel(void)
{
    int level = 0;
    while (Random(2)==0) level++;
    return level;
}
