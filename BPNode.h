//abstract class definition for B+-tree
template <typename Key, typename E> class BPNode
{
public:
    BPNode* lftptr;
    BPNode* rgtptr;
    virtual ~BPNode() {} 
    virtual bool isLeaf() const =0;
    virtual bool isFull() const =0;
    virtual int numrecs() const =0;	//number of recrods
    virtual Key* keys() const =0;	//return array of keys
}
