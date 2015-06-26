//compare shortest path distances from "s"
//return these distances in "D"
void Dijkstra(Graph* G, int* D, int s)
{
    int i,v,w;
    for (i=0; i<G->n(); i++)
    {
	v = minVertex(G,D);
	if (D[v] == INFINITY) return;
	G->setMark(v,VISITED);
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	    if (D[w] > (D[v]+G->weight(v,w)))
	        D[w] = D[v] + G->weight(v,w);
    }
}

int minVertex(Graph* G, int* D)
{
    int i,v =-1;
    //initialize v to some unvisited vertex
    for (i=0; i<G->n(); i++)
	if (G->getMark(i) == UNVISITED) {v=i;break;}
    for (i=0; i<G->n(); i++)
	if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
	    v=i;
    return v;
}

class DijkElem
{
public:
    int vertex, distance;
    DijkElem() {vertex = -1; distance = -1;}
    DijkElem(int v, int d) {vertex = v; distance = d;}
}；

//Dijkstra's shortest paths algorithm with priority queue
void Dijkstra(Graph* G, int* D, int s)
{
    int i,v,w;		//v is the current vertex
    DijkElem temp;
    DijkElem E[G->e()];	//heap array with lots of space
    temp.distance =0; temp.vertex =s;
    E[0] = temp;	//initialize heap array
    heap<DijkElem, DDComp> H(E,1, G->e());	//create heap
    for (i=0;i<G->n(); i++)			//now get distances
    {	
        do
	{
	    if (H.size() == 0) return;		//nothing to remove
	    temp = H.removefirst();
	    v=temp.vertex;
	} while (G->getMark(v) == VISITED);
	G->setMark(v,VISITED);
	if (D[v] == INFINITY) return;		//unreachable vertices
	for (w=G->first(v); w<G->n(); w=G->next(v,w))
	    if (D[w] > (D[v]+G->weight(v,w)))	//update D
	    {
		D[w] = D[v] + G->weight(v,w);
		temp.distance = D[w]; temp.vertex = w;
		H.insert(temp);		//insert new distance in heap
	    }
    }
}
