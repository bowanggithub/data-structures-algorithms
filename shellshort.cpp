//modified version of insertion sort for varying increments
template <typename E,typename Comp>
void inssort2(E A[], int n, int incr)
{
    for (int i=incr;i<n;i+=incr)
	for (int j=i;(j>=incr) && (Comp::prior(A[j],A[j-incr]));j-=incr)
	    swap(A,j,j-incr);
}

template <typename E,typename Comp>
void shellsort(E A[], int n)
{
    for (int i=n/2;i>2;i/=2)
	for (int j=0;j<i;j++)
	    inssort2<E,Comp>(&A[j],n-j,i);
    inssort2<E,Comp>(A,n,1);
}
