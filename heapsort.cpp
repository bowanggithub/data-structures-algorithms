template <typename E, typename Comp>
void heapsort(E A[], int n)
{
    E maxval;
    heap<E,Comp> H(A,n,n);
    for (int i=0;i<n;i++)
	maxval = H.removefirst();
}
