//return position of largest value in "A" of size "n"
int largest(int A[], int n)
{
    int currlarge = 0;			//holds largest element position
    for (int i=1;i<n;i++)		//for each array element
	if (A[currlarge] < A[i])	//if A[i] is larger
	    currlarge = i;		//remember its position
    return currlarge;			//return largest position
}
