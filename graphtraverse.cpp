void graphTraverse(Grpah* G)
{
    int v;
    for (v=0; v<G->n(); v++)
	G->setMark(v,UNVISITED);
    for (v=0;v<G->n(); v++)
	if (G->getMark(v) == UNVISITED)
	    doTraverse(G,v);
}

void DFS(Graph* G, int v)
{
    PreVisit(G,v);
    G->setMark(v, VISITED);
    for (int w=G->first(v); w<G->n(); w=G->next(v,w))
	if (G->getMark(w) == UNVISITED)
	    DFS(G,w);
    PostVisit(G,v);
}


void BFS(Graph* G, int start, Queue<int>* Q)
{
    int v,w;
    Q->enqueue(start);
    G->setMark(start, VISITED);
    while (Q->length() != 0)
    {
	v = Q->dequeue();
	PreVisit(G,v);
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	    if (G->getMark(w) == UNVISITED)
	    {
		G->setMark(w,VISITED);
		Q->enqueue(w);
	    }
    }
}

void topsort(Graph* G)
{
    int i;
    for (i=0; i<G->n(); i++)
	G->setMark(i,UNVISITED);
    for (i=0; i<G->n(); i++)
	if (G->getMark(i) == UNVISITED)
	    tophelp(G,i);
}

void tophelp(Graph* G, int v)
{
    G->setMark(v,VISITED);
    for (int w=G->first(v); w<G->n(); w=G->next(v,w))
	if (G->getMark(w) == UNVISITED)
	    tophelp(G,w);
    printout(v);
}

//topological sort: queue
void topsort(Graph* G, Queue<int>* G)
{
    int Count[G->n()];
    int v,w;
    for (v=0; v<G->n(); v++) Count[v] = 0;
    for (v=0; v<G->n(); v++) 
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	    Count[w]++;
    for (v=0; v<G->n(); v++)
	if (Count[v] == 0)
	    Q->enqueue(v);
    while (Q->length() != 0)
    {
	v=Q->dequeue();
	printout(v);
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	{
	    Count[w]--;
	    if (Count[w] == 0)
		Q->enqueue(w);
	}
    }
}
