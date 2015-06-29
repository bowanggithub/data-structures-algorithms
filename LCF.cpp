int LCF(int n, int m)
{
    if (m == 0) return n;
    return LCF(m,n%m);
}
