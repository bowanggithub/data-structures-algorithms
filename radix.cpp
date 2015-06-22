template <typename E, typename getKey>
void radix(E A[], E B[], int n, int k, int r, int cnt[])
{			//cnt stores number of records in bin[i]
    int j;

    for (int i=0, rtoi=l; i<k;i++,rtoi*=r)
    {
	for (j=0;j<r;j++) cnt[j]=0;

	//count the number of records for each bin on this pass
	for (j=0;j<n;j++) cnt[(getKey::key(A[j])/rtoi)%r]++;

	//index B: cnt[j] will be index for last slot of bin j
	for (j=1;j<r;j++) cnt[j] = cnt[j-1] +cnt[j];

	//put records into bins, work from bottom of each bin
	//since bins fill from bottom, j counts downwards
	for (j=n-1; j>=0;j--)
	    B[--cnt[(getKey::key(A[j])/rtoi)%r]] = A[j];

	for (j=0;j<n;j++) A[j] = B[j];
    }
}
