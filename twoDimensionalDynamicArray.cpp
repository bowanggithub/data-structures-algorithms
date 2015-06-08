int** M = new int*[n]
for (int i=0;i<n;i++)
    M[i] = new int [m];
    
for (int i=0;i<n;i++)
    delete [] M[i];
delete [] M;
