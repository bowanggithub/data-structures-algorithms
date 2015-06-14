//HuffTree is a template of two parameters: the element
//type being coded and a comparator for two such elements
template <typename E>
class HuffTree
{
private:
    HuffNode<E>* Root;
public:
    HuffTree(E& val, int freq)		//leaf constructor
    {
	Root = new LeafNode<E>(val,freq);
    }
    //internal node constructor
    HuffTree(HuffTree<E>* l, HuffTree<E>* r)
    {
	Root = new IntlNode<E>(l-root(),r->root());
    }
    ~HuffTree() {}
    HuffNode<E>* root() {return Root;}
    int weight() {return Root->weight();}
};
