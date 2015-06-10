//singly linked list node with freelist support
template <typename E> class Link
{
public:
    E element;				//value of this node
    Link *next;				//pointer to the next node in list
    //constructors
    Link(const E& elemval, Link* nextval =NULL)
    {
	element = elemval;
	next = nextval;
    }
    Link(Link* nextval =NULL)
    {
	next = nextval;
    }





private:
    static Link<E>* freelist;		//reference to freelist head
public:
    void* operator new(size_t)		//overload the new operator
    {
	if (freelist == NULL) return ::new Link;		//if freelist is empty then create new space
	Link<E>* temp = freelist;				//if freelist is not empty then take from freelist
	freelist = freelist->next;
	return temp;						//return the link
    }

    void operator delete(void* ptr)	//overload the delete operator
    {
	((Link<E>*)ptr)->next = freelist;			//put on freelist
	freelist = (Link<E>*)ptr;
    }

};

//The freelist head pointer is actually created outside the definition of the class Link
template<typename E>
Link<E>* Link<E>::freelist = NULL;
