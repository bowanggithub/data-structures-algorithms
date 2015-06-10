//doubly linked list link node with freelist support
template <typename E> class Link
{
private:
    static Link<E>* freelist;			//reference to the freelist head

public:
    E element;					//value of the node
    Link* next;					//pointer to the next node
    Link* prev;					//pointer to the previous node

    //constructors
    Link(const E& it, Link* prevp, Link* nextp)
    {
	element = it;
	prev = prevp;
	next = nextp;
    }

    Link(Link* prevp=NULL, Link* nextp =NULL)
    {
	prev = prevp;
	next = nextp;
    }

    void* operator new(size_t)
    {
	if (freelist == NULL) return ::new Link;
	Link<E>* temp = freelist;
	freelist = freelist->next;
	return temp;
    }

    void operator delete(void* ptr)
    {
	((Link<E>*)ptr)->next = freelist;
	freelist = (Link<E>*)ptr;
    }
};

//The freelist head pointer is actuallt created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;
