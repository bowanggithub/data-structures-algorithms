template <typename E, typename Comp>
void inssort(E A[], int n)
{
    for (int i=1; i<n; i++)
    {
	for (int j=i;(j>0)&& (Comp::prior(A[j],A[j-1]));j--)
	    swap(A,j,j-1);
    }
}
