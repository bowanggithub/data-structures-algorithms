long fibi(int n)	//iterative fibonacci generator
{
    //fibi(46) is largest value that fits in a long
    Assert((n>0)&&(n<47), "input out of range");
    long past, prev, curr;
    past=prev=curr=1;
    for (int i=3;i<=n;i++)
    {
	past = prev; prev = curr;
	curr = past + prev;
    }
    return curr;
}
