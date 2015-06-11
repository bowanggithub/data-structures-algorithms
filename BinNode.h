//binary tree node abstract class
template <typename E> class BinNode
{
public:
    virtual ~BinNode() {}

    //return the node's value
    virtual E& element() =0;

    //set the node's value
    virtual void setElement(const E&) =0;

    //return the node's left child
    virtual BinNode* left() const =0;

    //set the node's left child
    virtual void setLeft(BinNode*) =0;

    //return the node's right child
    virtual BinNode* right() const =0;

    //set the node's right child
    virtual void setRight(BinNode*) =0;

    //return true is the node is a leaf, false otherwise
    virtual bool isLeaf() =0;
};


