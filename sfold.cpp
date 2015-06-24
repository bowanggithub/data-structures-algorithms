//use folding on a string, summed 4 bytes at a time
int sfold(char* key)
{
    unsigned int *lkey = (unsigned int *)key;
    int intlength = strlen(key)/4;
    unsigned int sum =0;
    for (int i=0;i<intlength;i++)
    {
	sum += lkey[i];
    }

    //now deal with the extra chars at the end
    int extra = strlen(key) - intlength*4;
    char temp[4];
    lkey = (unsigned int *) temp;
    lkey[0]=0;
    for (int i=0;i<extra;i++)
	temp[i] = key[intlength*4+i];
    sum += lkey[0];

    return sum % M;
}
