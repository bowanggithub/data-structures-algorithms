template <typename E> class List
{
private:
    void operator =(const List&) {}			//protect assignment
    List(const List&)					//protect copy constructor
public:
    List() {}						//default constructor
    virtual ~List() {}					//base destructor

    //clear contents from the list, to make it empty
    virtual void clear()=0;

    //Insert an element at the current location
    //item: the element to be inserted
    virtual void insert(const E& item) =0;

    //append an element at the end of the list
    //item: the lement to be appended
    virtual void append(const E& item) =0;

    //remove and return the current element
    //return: the element that was removed
    virtual E remove() =0;

    //set the current position to the start of the list
    virtual void moveToStart() =0;

    //set the current position to the end of the list
    virtual void moveToEnd() =0;

    //move the current position one step left. No change
    //if already at beginning
    virtual void prev() =0;

    //move the current position one step right. No change
    //is already at the end
    virtual void next() =0;

    //return: the number of elements in the list
    virtual int length() const =0;

    //return : the position of the current element
    virtual int currPos() const =0;

    //set current position
    //pos: the position to make current
    virtual void moveToPos(int pos) =0;

    //return: the current element
    virtual const E& getValue() const =0;
};

for (L.moveToStart(); L.currPos()<L.length();L.next())
{
    it = L.getValue();
    doSomneThing(it);
}

//return true if "K" is in list "L", false otherwise
bool find(List<int>& L, int K)
{
    int it;
    for (L.moveToStart(); L.currPos()<L.length(); L.next())
    {
	it = L.getValue();
	if (K == it) return true;				//found "K"
    }
    return false;						//not found
}

