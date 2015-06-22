template <typename E, class getKey>
void binsort(E A[], int n)
{
    List<E> B[MaxKeyValue];
    E item;
    for (int i=0; i<n; i++) B[A[i]].append(getKey::key(A[i]));
    for (int i=0;i<MaxKeyValue;i++)
	for (B[i].setStart(); B[i].getValue(item);B[i].next())
	    output(item);
}
