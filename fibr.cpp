long fibr(int n)		//recursive Fibonacci generator
{			//fibr(46) is largest value fits in a long
    Assert((n>0)&&(n<47),"Input out of range");
    if ((n == 1) || (n == 2)) return 1;
    return fibr(n-1)+fibr(n-2);
}
