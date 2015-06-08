#include <cstdlib>
#include <iostream>
using namespace std;

const int X=1, O=-1,EMPTY=0;
int board[3][3];
int currentPlayer;

void clearBoard()
{
    for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
	    board[i][j] = EMPTY;
    currentPlayer = X;
}

void putMark(int i,int j)
{
    board[i][j] = currentPlayer;
    currentPlayer = -currentPlayer;
}

bool isWin(int mark)
{
    int win = 3*mark;
    return ((board[0][0]+board[0][1]+board[0][2]==win)
    	||(board[1][0]+board[1][1]+board[1][2]==win)
	||(board[2][0]+board[2][1]+board[2][2]==win)
	||(board[0][0]+board[1][0]+board[2][0]==win)
	||(board[0][1]+board[1][1]+board[2][1]==win)
	||(board[0][2]+board[1][2]+board[2][2]==win)
	||(board[0][0]+board[1][1]+board[2][2]==win)
	||(board[2][0]+board[1][1]+board[0][2]==win));
}

int getWinner()
{
    if (isWin(X)) return X;
    else if (isWin(O)) return O;
    else return EMPTY;
}

void printBoard()
{
    for (int i=0;i<3;i++)
    {
	for (int j=0;j<3;j++)
	{
	    switch (board[i][j])
	    {
		case X:		cout << "X";break;
		case O:		cout << "O";break;
		case EMPTY:	cout << " ";break;
	    }
	    if (j<2) cout << "|";
	}
	if (i<2) cout << "\n-+-+-\n";
    }
}

int main()
{
    clearBoard();
    putMark(0,0);	putMark(1,1);
    putMark(0,1);	putMark(0,2);
    putMark(2,0);	putMark(1,2);
    putMark(2,2);	putMark(2,1);
    putMark(1,0);
    printBoard();
    int winner = getWinner();
    if (winner != EMPTY)
	cout << " " << (winner == X ? 'X': 'O') << " wins" << endl;
    else
	cout << "Tie" << endl;
    
    return 0;
}

