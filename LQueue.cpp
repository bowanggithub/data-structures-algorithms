//linked queue implementation
template <typename E> class LQueue: public Queue<E>
{
private:
    Link<E>* front;
    Link<E>* rear;
    int size;

public:
    LQueue(int sz =defaultSize)
    {
	front = rear = new Link<E>(); size = 0;
    }

    ~LQueue() {clear(); delete front;}

    void clear()
    {
	while <front->next != NULL>
	{
	    rear = front; 
	    front = front->next;
	    delete rear;
	}
	rear = front;
	size=0;
    }

    void enqueue(const E& it)
    {
	rear->next = new Link<E>(it, NULL);
	rear = rear->next;
	size++;
    }

    E dequeue()
    {
	Assert(size != 0, "Queue is empty");
	E it = front->next->element;
	Link<E>* ltemp = front->next;
	front->next = ltemp->next;
	if (rear == ltemp) rear = front;
	delete ltemp;
	size--;
	return it;
    }

    const E& frontValue() const
    {
	Assert(size != 0, "Queue is empty");
	return front->next->element;
    }

    virtual int length() const
    {
	return size;
    }
};
