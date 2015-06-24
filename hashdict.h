//dictionary implemented with a hash table
template <typename Key,typename E>
class hashdict : public Dictionary<Key, E>
{
private:
    KVpair<Key,E>* HT;
    int M;				//size
    int currcnt;			//current number of elements
    Key EMPTYKEY;	//user supplied key value for an empty slot

    int p(Key K, int i) const	//probe using linear probing
        {return i;}

    int h(int x) const {return x % M;}	//poor hash function
    int h(char* x) const 		//hash function for char keys
    {
	int i,sum;
	for (sum =0,i=0;x[i] != '\0';i++)
	    sum += (int) x[i];
	return sum% M;
    }

    void hashInsert(const Key&, const E&);
    E hashSearch(const Key&) const;

public:
    hashdict(int sz, Key k)	//"k" defines an empty slot
    {
	M=sz;
	EMPTYKEY = k;
	currcnt = 0;
	HT= new KVpair<Key, E>[sz];
	for (int i=0; i<M;i++)
	    (HT[i]).setKey(EMPTYKEY);
    }

    ~hashdict() {delete HT;}

    //find some record with key value "K"
    E find(const Key& k) const
        {return hashSearch(k);}
    int size() {return currcnt; }

    //insert element "it" with Key "k" into the dictionary
    void insert(const Key& k, const E& it)
    {
	Assert(currcnt < M, "Hash table is full");
	hashInsert(k,it);
	currcnt++;
    }
}

