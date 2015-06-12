//simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E>
{
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;

public:
    //two constructors -- with and without initial values
    BSTNode() {lc=rc=NULL;}
    BSTNode(Key K, E e, BSTNode * l=NULL, BSTNode* r=NULL)
        {k=K; it = e; lc = l; rc = r;}
    ~BSTNode() {}

    //functions to set and return the value and key
    E& element() {return it;}
    void setElement(const E& e) {it =e;}
    Key& key() {return k;}
    void setKey(constKey& K) {k=K;}

    //functions to set and return the children
    inline BSTNode* left() const {return lc;}
    void setLeft(BinNode<E>* b) {lc = (BSTNode*)b;}
    inline BSTNode* right() const {return rc;}
    void setRight(BinNode<E>* b) {rc = (BSTNode*)b;}

    //return true if it is a leaf, false otherwise
    boll isLeaf() {return (lc==NULL) && (rc==NULL);}
};
