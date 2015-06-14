//general tree node ADT
template <typename E> class GTNode
{
public:
    E value();
    bool isLeaf();
    GTNode* parent();
    GTNode* leftmostChild();
    GTNode* rightSibling();
    void setValue(E&);
    void insertFirst(GTNode<E>*);
    void insertNext(GTNode<E>*);
    void removeFirst();
    void removeNext();
};

//general tree ADT
template <typename E> class GenTree
{
public:
    void clear();
    GTNode<E>* root();
    //combine two subtrees
    void newroot(E&, GTNode<E>*, GTNode<E>*);
    void print();
};
