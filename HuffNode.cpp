//Huffman tree node abstract base class
template <typename E> class HuffNode
{
public:
    virtual ~HuffNode() {}
    virtual int weight() =0;
    virtual bool isLeaf() =0;
};

template <typename E>
class LeafNode : public HuffNode<E>
{
private:
    E it;
    int wgt;
public:
    LeafNode(const E& val, int freq)
    {
	it = val;
	wgt = freq;
    }
    int weight() {return wgt;}
    E val() {return it;}
    bool isLeaf() {return true;}
};

template<typename E>
class IntlNode : public HuffNode<E>
{
private:
    HuffNode<E>* lc;
    HuffNode<E>* rc;
    int wgt;
public:
    IntlNode(HuffNode<E>* l, HuffNode<E>* r)
    {
	wgt = l->weight() + r->weight();
	lc = l;
	rc = r;
    }
    int weight() {return wgt;}
    bool isLeaf() {return false;}
    HuffNode<E>* left() const {return lc;}
    void setLeft(HuffNode<E>* b)
    {
	lc = (HuffNode<E>*)b;
    }
    HuffNode<E>* right() const {return rc;}
    void setRight(HuffNode<E>* b)
    {
	rc = (HuffNode<E>*)b;
    }
};
