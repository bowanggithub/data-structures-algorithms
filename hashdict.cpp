//insert e into hash table HT
template <typename Key, typename E>
void hashdict<Key,E>::
hashInsert(const Key& k, const E& e)
{
    int home;				//home position
    int pos = home =h(k);		//initial probe sequence
    for (int i=1; EMPTYKEY != (HT[pos]).key();i++)
    {
	pos = (home + p(k,i)) % M;		//probe
	Assert(k != (HT[pos]).key(), "Duplicates not allowed");
    }
    KVpair<Key,E> temp(k,e);
    HT[pos] =temp;
}

//search for the record with Key K
template <typename Key, typename E>
E hashdict<key,E>::hashSearch(const Key& k) const
{
    int home;
    int pos = home = h(k);
    for (int i=1;(k != (HT[pos]).key()) && 
		(EMPTYKEY != (HT[pos]).key());i++)
	pos = (home + p(k,i)) % M;
    if (k == (HT[pos]).key())
	return (HT[pos]).value();
    else return NULL;
}
