void insertionSort(char* A, int n)
{
    for (int i=1;i<n;i++)
    {
	char cur = A[i];
	int j=i-1;
	while ((j>=0) && (A[j]>cur))
	{
	    A[j+1]=A[j];
	    j--;
	}
	A[j+1] =cur;
    }
}
