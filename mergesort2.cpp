template <typename E, typename Comp>
void mergesort(E A[], E temp[], int left, int right)
{
    if ((right-left) <= THRESHOLD)
    {
	inssort<E, Comp>(&A[left], right-left+1);
	return;
    }
    int i,j,k,mid = (left+right)/2;
    mergesort<E,comp>(A,temp,left,mid);
    mergesort<E,Comp>(A,temp,mid+1,right);
    //do the merge operation. First copy 2 halves to temp
    for (i=mid;i>=left;i--) temp[i] = A[i];
    for (j=1;j<=right-mid;j++) temp[right-j+1] = A[j+mid];
    //merge sublists back to A
    for (i=left, j=right, k=left; k<=right;k++)
	if (Comp::prior(temp[i], temp[j])) A[k] = temp[i++];
	else A[k] = temp[j--];
}
