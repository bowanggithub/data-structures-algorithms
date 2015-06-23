//ADT for buffer pools using the message-passing style
class BufferPool
{
public:
    //copy "sz" bytes from "space" to position "pos" in the 
    //buffered storage
    virtual void insert(void* space, int sz, int pos) =0;


    //copy "sz" bytes from position "pos" of the buffered
    //storage to "space"
    virtual void getbytes(void* space, int sz, int pos) =0;
};



//ADT for buffer pools using the buffer-passing style
class BufferPool
{
public:
    //return pointer to the requested block
    virtual void* getblock(int block) =0;

    //set the dirty bit for thr buffer holding "block"
    virtual void dirtyblock(int block) =0;

    //tell the size of a buffer
    virtual int blocksize() =0;
};
