//Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created
class Graph
{
private:
    void operator =(const Graph&) {}	//protect assignment
    Graph(const Graph&) {} 		//protect copy constructor

public:
    Graph() {}
    virtual ~Graph() {}

    //initialize a graph of n vertices
    virtual void Init(int n) =0;

    //Return: the number of vertices and edges
    virtual int n() =0;
    virtual int e() =0;

    //return v's first neighbor
    virtual int first(int v) =0;

    //return v's next neighbor after w
    virtual int next(int v, int w) =0;

    //set the weight for an edge
    //i,j: the vertices
    //wgt: Edge weight
    virtual void setEdge(int v1, int v2, int wght) =0;

    //delete an edge
    //i,j: the vertices
    virtual void delEdge(int v1, int v2) =0;

    //determine if an edge is in the graph
    //i,j: the veritices
    //return: true if edge i,j has a non-zero weight
    virtual bool isEdge(int i, int j) =0;

    //return an edge's weight
    //i,j: the vertices
    //return: the weight of edge i,j, or zero
    virtual int weight(int v1, int v2) =0;

    //get and set the mark value for a vertex
    //v: the vertex
    //val: the value to set
    virtual int getMark(int v) =0;
    virtual void setMark(int v, int val) =0;
};
