//Memory manager abstract class
class MemManager
{
public:
    virtual ~MemManager() {}

    //store a record and return a handle to it
    virtual MemHandle insert(void* info, int length) =0;

    //Get back a copy of a stored record
    virtual int get(void* info, MemHandle h) =0;

    //release the space associated with a record
    virtual void release(MemHandle h) =0;
};
