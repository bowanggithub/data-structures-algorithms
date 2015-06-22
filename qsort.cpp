template <typename E, typename Comp>
void qsort(E A[], int i, int j)
{
    if (j <= i) return; //don't sort 0 or 1 element
    int pivotindex = findpivot(A,i,j);
    swap(A, pivotindex,j);	//put pivot at end
    // k will be the first position in the right subarray
    int k = partition<E,Comp>(A, i-1,j, A[j]);
    swap(A,k,j);
    qsort<E,Comp>(A,i,k-1);
    qsort<E,Comp>(A,k+1,j);
}

template <typename E>
inline int findpivot(E A[], int i, int j)
	{return (i+j)/2;}


template <typename E, typename Comp>
inline int partition(E A[], int l ,int r, E& pivot)
{
    do
    {
	while (Comp::prior(A[++l],pivot));
	while ((l < r) && Comp::prior(pivot,A[--r]));
	swap(A, l, r);
    } while (l<r);
    return 1;
}
