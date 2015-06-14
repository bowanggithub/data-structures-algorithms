//general tree representation for UNION/FIND
class ParPtrTree
{
private:
    int* array;
    int size;
    int FIND(int) CONST;
public:
    ParPtrTree(int);
    ~ParPtrTree() {delete [] array;}
    void UNION(int,int);
    bool differ(int,int);
};

int ParPtrTree::FIND(int curr) const
{
    while (array[curr] != ROOT) curr = array[curr];
    return curr;
}

//FIND with path compression
int ParPtrTree::FIND(int curr) const
{
    if (array[curr] == ROOT) return curr;
    array[curr] = FIND(array[curr]);
    return array[curr];
}
