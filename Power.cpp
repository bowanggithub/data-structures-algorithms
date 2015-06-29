int Power(base, exp)
{
    if exp = 0 return 1;
    int half = Power(base, exp/2);
    half = half* half;
    if (odd(exp)) then half = half* base;
    return half;
}
