//Node implementation with simple inheritance
class VarBinNode
{
public:
    virtual ~VarBinNode() {}
    virtual bool isLeaf() =0;
};


class LeafNode : public VarBinNode
{
private:
    Operand var;

public:
    LeafNode(const Operand& val) {var = val;}
    bool isLeaf() {return true;}
    Operand value() {return var;}
};


class IntlNode : public VarBinNode
{
private:
    VarBinNode* left;
    VarBinNode* right;
    Operator opx;

public:
    IntlNode(const Operator& op, VarBinNode* l, VarBinNode* r)
        {opx=op;left=l;right=r;}
    bool isLeaf() {return false;}
    VarBinNode* leftchild() {return left;}
    VarBinNode* rightchild() {return right;}
    Operator value() {return opx;}
};

void traverse(VarBinNode* root)
{
    if (root == NULL) return;
    if (root->isLeaf())
	cout << "Leaf: " << ((LeafNode *)root)->value() << endl;
    else
    {
	cout << "Internal: "
	     << ((IntlNode *)root)->value() << endl;
	traverse(((IntlNode *)root)->leftchild());
	traverse(((IntlNode *)root)->rightchild());
    }
}

