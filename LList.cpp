//linked list implementation
template <typename E> class LList: public List<E>
{
private:
    Link<E>* head;					//pointer to list header
    Link<E>* tail;					//pointer to last element
    Link<E>* curr;					//access to current element
    int cnt;						//size of list

    void init()						//initialization helper method
    {
	curr = tail = head = new Link<E>;
	cnt = 0;
    }

    void removeall()					//return link nodes to free store
    {
	while(head != NULL)
	{
	    curr = head;
	    head = head->next;
	    delete curr;
	}
    }


public:
    LList(int size=defaultSize)				//constructor
    {
	init();
    }

    ~LList()						//destructor
    {
	removeall();
    }

    void print() const;					//print list contents
    void clear()					//clear
    {
	removeall();
	init();
    }

    //insert "it" at current position
    void insert(const E& it)
    {
	curr->next = new Link<E>(it, curr->next);
	if (tail == curr) tail = curr->next;		//new tail
	cnt++;
    }

    void append(const E& it)				//append "it" to list
    {
	tail = tail->next = new Link<E>(it,NULL);
	cnt++;
    }

    //remove and return current element
    E remove()
    {
	Assert(curr->next != NULL, "no element");
	E it = curr->next->element;			//remember value
	Link<E>* ltemp = curr->next;			//remember link node in order to delete
	if (tail == curr->next) tail = curr;		//reset tail if the last emement is removed
	curr->next = curr->next->next;			//remoev from list
	delete ltemp;					//reclaim space
	cnt--;
	return it;
    }

    void moveToStart()					//place curr at list start
    {
	curr = head;
    }

    void moveToEnd()					//place curr at list end
    {
	curr = tail;
    }

    //move curr one step left; no change if already at front
    void prev()
    {
	if (curr=head) return;				//no previous element
	Link<E>* temp = head;
	//march down list until we find the previous element
	while (temp->next!=curr) temp = temp->next;
	curr = temp;
    }

    //move curr one step right; no change if already at end
    void next()
    {
	if (curr!=tail)
	    curr = curr->next;
    }

    int length() const					//return length
    {
	return cnt;
    }

    //return the position of the current element
    int currPos() const
    {
	Link<E>* temp = head;
	int i;
	for (i=0; curr!=temp;i++)
	    temp=temp->next;
	return i;
    }

    //move down list to "pos" position
    void moveToPos(int pos)
    {
	Assert((pos>=0)&&(pos<=cnt), "Position out of range");
	curr = head;
	for(int i=0;i,pos;i++)
	    curr = curr->next;
    }

    const E& getValue() const				//return current element
    {
	Assert(curr->next!=NULL, "no element");
	return curr->next->element;
    }
};
