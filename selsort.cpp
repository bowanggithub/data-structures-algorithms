template <typename E,typename Comp>
void selsort(E A[], int n)
{
    for (int i=0; i< n-1;i++)
    {
	int lowindex = i;
	for (int j=n-1;j>i;j--)
	    if (Comp::prior(A[j],A[lowindex]))
		lowindex = j;
	swap(A,i,lowindex);
    }
}
