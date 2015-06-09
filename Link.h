//singly linked list node
template <typename E> calss Link
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
};
