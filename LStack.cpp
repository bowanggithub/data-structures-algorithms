//linked stack implementation
template <typename E> class LStack: public Stack<E>
{
private:
    Link<E>* top;
    int size;

public:
    LStack(int sz =defaultSize)
    {
	top = NULL;
	size=sz;
    }

    ~LStack() 
    {
	clear();
    }

    void clear()
    {
	while (top != NULL)
	{
	    Link<E>* temp = top;
	    top = top->next;
	    delete temp;
	}
	size=0;
    }

    void push(const E& it)
    {
	top = new Link<E>(it top);
	size++;
    }

    E pop()
    {
	Assert(top != NULL, "stack is empty");
	E it = top->element;
	Link<E>* ltemp = top->next;
	delete top;
	top = ltemp;
	size--;
	return it;
    }

    const E& topValue() const
    {
	Assert(top != 0, "stack is empty");
	return top->element;
    }

    int length() const
    {
	return size;
    }
};
