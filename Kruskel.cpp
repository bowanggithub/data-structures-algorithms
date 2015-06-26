class KruskElem
{
public:
    int from, to, distance;
    KruskElem() {from = -1; to = -1; distance = -1;}
    KruskElem(int f, int t, int d)
    	{from = f, to = t; distance = d;}
};

void Kruskel(Graph* G)
{
    ParPtrTree A[G->n()];
    KruskElem E[G->n()];
    int i;
    int edgecnt = 0;
    for (i=0; i<G->n(); i++)
	for (int w=G->first(i); w<G->n(); w=G->next(i,w))
	{
	    E[edgecnt].distance = G->weight(i,w);
	    E[edgecnt].from = i;
	    E[edgecnt].to = w;
	}

    //heapify the edges
    heap<KruskElem, Comp> H(E, edgecnt, edgecnt);
    int numMST = G->n();
    for (i=0; numMST>1; i++)
    {
	KruskElem temp;
	temp = H.removefirst();
	int v = temp.from; int u=temp.to;
	if (A.differ(v,u))		//if in different classes
	{
	    A.UNION(v,u);
	    AddEdgetoMst(temp.from,temp.to);
	    numMST--;
	}
    }
}
