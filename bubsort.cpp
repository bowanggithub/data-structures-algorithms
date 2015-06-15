template <typename E, typename Comp>
void bussort(E A[], int n)
{
    for (int i=0; i<n-1;i++)
	for (int j=n-1;j>i;j--)
	    if (Comp::prior(A[j],A[j-1]))
		swap(A,j,j-1);
}
