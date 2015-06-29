//Floyd's all-pair shortest paths algorithm
//Store the pair-wise distance in "D"
void Floyd(Graph* G)
{
    //initialize D with weights
    for (int i=0; i<G->n();i++)
	for (int j=0; j<G->n();j++)
	    if (G->weight(i,j) != 0)
		D[i][j] = G->weight(i,j);

    //compute all k paths
    for (int k=0; k<G->n(); k++)
	for (int i=0; i<G->n(); i++)
	    for (int j=0; j<G->n(); j++)
		if (D[i][j] > (D[i][k] + D[k][j]))
		    D[i][j] = D[i][k] + D[k][j];
}
