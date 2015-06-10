long fact(int n, Stack<int>& S)
{
    //to fit n! in a long variable, require n<=12
    Assert((n>=0)&&(n<=12), "input out of range");
    while (n>1) S.push(n--);
    long result = 1;
    while(S.length() >0)
	result = result*S.pop();
    return result;
}
