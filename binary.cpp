//return the position of an element in sorted array "A" of 
//size "n" with value "K". If "k" is not in "A", return 
//the value "n"
//#include <iostream>
//using namespace std;
int binary(int A[],int n, int K)
{
    int l=-1;
    int r=n;					//l and r are beyond array bounds
    while (l+1 != r)				//stop when l and r meet
    {
	int i=(l+r)/2;
	if (K < A[i]) r=i;			//in left half
	if (K == A[i]) return i;		//found it
	if (K > A[i]) l=i;			//in right half
    }
    return n;					//search value not in A
}

/*
int main()
{
    int A[4]={1,2,3,4};
    int n=4;
    int K=3;
    cout << binary(A,n,K) << endl;
    return 0;
}
*/
