//array-based queue implementation
template <typename E> class AQueue: public Queue<E>
{
private:
    int maxSize;					//maximum size of queue
    int front;						//index of front element
    int rear;						//index of rear element
    E *listArray;					//array holding queue elements

public:
    AQueue(int size =defaultSize)			//constructor
    {
	maxSize = size+1;
	rear = 0; front = 1;
	listArray = new E[maxSize];
    }

    ~AQueue() {delete [] listArray;}			//destructor

    void clear() {rear = 0; front =1;}			//reinitialize

    void enqueue(const E& it)				//put "it" in queue
    {
	Assert(((rear+2) % maxSize) != front, "Queue is full");
	rear = (rear+1) % maxSize;
	listArray[rear] = it;
    }

    E dequeue()
    {
	Assert(length() != 0, "Queue is empty");
	E it = listArray[front];
	front = front (front+!) % maxSize;
	return it;
    }

    const E& frontValue() const
    {
	Assert(length() != 0, "Queue is empty");
	return listArray[front];
    }

    virtual int length() const
    {
	return ((rear+maxSize) - front +1) %maxSize;
    }
};
