//dictionary implementation with an unsorted array-based list
template <typename Key, typename E>
class UALdict : public Dictionary<Key ,E>
{
private:
    AList<KVpair<Key,E> >* list;

public:
    UALdict(int size=defaultSize)
        {list = new AList<KVpair<Key,E> >(size);}
    ~UALdict() {delete list;}
    void clear() {list->clear();}

    //insert an element: append to list
    void insert(const Key& k, const E& e)
    {
	KVpair<Key,E> temp(k,e);
	list->append(temp);
    }

    //use sequential search to find the element to remove
    E remove(const Key& k)
    {
	E temp = find(k);
	if (temp != NULL) list->remove();
	return temp;
    }

    E removeAny()
    {
	Assert(size() != 0, "dictionary is empty");
	list->moveToEnd();
	list->prev();
	KVpair<Key,E> e=list->remove();
	return e.value();
    }

    //Find "k" using sequential search
    E find(const Key& k) const 
    {
	for (list->moveToStart();
	    list->currPos() < list->length();list->next())
	{
	    KVpair<Key,E> temp = list->getValue();
	    if (k == temp.key())
		return temp.value();
	}
	return NULL;
    }

    int size()
    {
	return list->length();
    }
};
