int Fibrt(int n, int* Values)
{		//assume values has at least n slots, and all
		//slots are initialized to 0
    if (n <= 1) return 1;
    if (Values[n] != 0)
	Values[n] = Fibrt(n-1,Values) + Fibrt(n-2, Values);
    return Values[n];
}
