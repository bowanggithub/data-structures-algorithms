//Stack abstract class
template <typename E> class Stack
{
private:
    void operator =(const Stack&) {}			//protect assignment
    Stack(const Stack&) {}				//protect copy constructor

public:
    Stack() {}						//constructor
    virtual ~Stack() {}					//destructor

    //reinitialize the stack. The user is responsible for 
    //reclaiming the storage used by the stack elements
    virtual void clear() =0;

    //push an element onto the top of the stack
    //it: the element being pushed onto the stack
    virtualvoid push(const E& it) =0;

    //remove the element at the top of the stack
    //return the element at the top of the stack
    virtual E pop() =0;

    //return A copy of the top element
    virtual const E& topValue() const =0;

    //return the number of elements in the stack
    virtual int length() const =0;
};
