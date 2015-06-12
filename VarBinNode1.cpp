//node implementation with the composite design pattern
class VarBinNode
{
public:
    virtual ~VarBinNode() {}
    virtual bool isLeaf() =0;
    virtual void traverse() =0;
};


class LeafNode : public VarBinNode
{
private:
    Operand var;

public:
    LeafNode(const Operand& val) {var=val;}
    bool isLeaf() {return true;}
    Operand value() {return var;}
    void traverse() {cout << "Leaf: " << value() << endl;}
};


class IntlNode : public VarBinNode
{
private:
    VarBinNode* lc;
    VarBinNode* rc;
    Operator opx;

public:
    IntlNode(const Operator& op, VarBinNode* l, VarBinNode* r)
        {opx=op;lc=l;rc=r;}
    bool isLeaf() {return false;}
    VarBinNode* left() {return lc;}
    VarBinNode* right() {return rc;}
    Operator value() {return opx;}

    void traverse()
    {
	cout << "Internal: " << value() << endl;
	if (left() != NULL) left()->traverse();
	if (right() != NULL) right()->traverse();
    }
};


void traverse(VarBinNode* root)
{
    if (root != NULL) root->traverse();
}
