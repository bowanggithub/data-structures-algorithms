void Prim(Graph* G, int* D, int s)
{
    int V[G->n()];
    int i,w;
    for (i=0; i<G->n(); i++)
    {
	int v = minVertex(G,D);
	G->setMark(v,VISITED);
	if (v != s)
	    AddEdgetoMST(V[v],v);
	if (D[v] == INFINITY) return;
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	    if (D[w] > G->weight(v,w))
	    {
		D[w] = G->weight(v,w);
		V[w] = v;
	    }
    }
}
