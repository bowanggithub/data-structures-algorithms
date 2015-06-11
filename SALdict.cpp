//Dictionary implementation with a sorted array-based list
template <typename Key, typename E>
class SALdict : public Dictionary<Key,E>
{
private:
    SAList<Key,E>* list;

public:
    SALdict(int size=defaultSize)
    {
	list = new SAList<Key,E>(size);
    }
    ~SALdict()
    {
	delete list;
    }
    void clear()
    {
	list->clear();
    }

    //insert an element: keep elements aorted
    void insert(const Key& k, const E& e)
    {
	KVpair<Key,E> temp(k,e);
	list->insert(temp);
    }

    //use binary search to find the element to remove
    E remove(const Key& k)
    {
	E temp = find(k);
	if (temp != NULL) list->remove();
	return temp;
    }

    E removeAny()
    {
	Assert(size() != 0, "Dictionary is empty");
	list->moveToEnd();
	list->prev();
	KVpair<Key,E> e = list->remove();
	return e.value();
    }

    //find "k" using binary search
    E find(const Key& k) const
    {
	int l = -1;
	int r = list->length();
	while (l+1 != r)
	{
	    int i=(l+r)/2;
	    list->moveToPos(i);
	    KVpair<Key,E> temp = list->getValue(0;
	    if (k < temp.key()) r=i;
	    if (k == temp.key()) return temp.value();
	    if (k > temp.key()) l=i;
	}
	return NULL;
    }

    int size()
    {
	return list->length();
    }
};
