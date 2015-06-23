//a single buffer in the buffer pool
class Buffer
{
public:
    //read the associated block from disk (if necessary) and
    //return a pointer to the data
    void *readBlock() =0;

    //return a pointer to the buffer's data array
    //without reading from disk
    void *getDataPointer() =0;

    //flag the buffer's contents as having changed, so that
    //flushing the block will write it back to disk
    void markDirty() =0;

    //release the block's access to this buffer. further
    //access to this buffer are illegal
    void releaseBuffer() =0;
}

//the bufferpool
class BufferPool
{
public:
    //constructor: the bufferpool has "numbuff" buffers that
    //each contain "buffersize" bytes of data
    BufferPool(int numbuff, int buffsize) =0;

    //release a block to a buffer, returning a pointer to a 
    //buffer object
    Buffer *acquireBuffer(int block) =0;
}
