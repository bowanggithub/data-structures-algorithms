Fourier_Transform(double *Polynomial, int n)
{
    //compute the Fourier transform of polynomial
    //with degree n. Polynomial is a list of 
    //coefficients indexed from 0 to n-1. n is
    // assumed to be a power of 2
    double Even[n/2], Odd[n/2], List1[n/2], List2[n/2];

    if (n==1) return Polynomial[0];

    for (j=0; j<= n/2-1; j++)
    {
	Even[j] = Polynomial[2j];
	Odd[j] = Polynomial[2j+1];
    }
    List1 = Fourier_Transform(Even, n/2);
    List2 = Fourier_Transform(Odd, n/2);
    for (j=0;j<=n-1;j++)
    {
	Imaginary z = pow(E, 2*i*PI*j/n);
	k=j%(n/2);
	Polynomial[j] = List1[k]+ z*List2[k];
    }
    return Polynomial;
}
