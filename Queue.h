//abstract queue class
template <typename E> class Queue
{
private:
    void operator = (const Queue&) {} 			//protect assignment
    Queue(const Queue&) {}				//protect copy constructor

public:
    Queue() {}						//default constructor
    virtual ~Queue() {}					//destructor

    //reinitialize the queue. The user is responsible for 
    //reclaiming the storage used by the queue elements
    virtual void clear() =0;

    //place an element at the rear of the queue
    //it: the element being enqueued
    virtual void enqueue(const E&) =0;

    //remove and return element at the front of the queue
    //return: the element at the front of the queue
    virtual E dequeue() =0;

    //return: a copy of the front element
    virtual const E& frontValue() const =0;

    //return: the number of elements in the queue
    virtual int length() const =0;
};
