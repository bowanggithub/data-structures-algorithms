//operation choices: DOMOVE will move a disk
//DOTOH corresponds to a recursive call
enum TOHop {DOMOVE, DOTOH};
class TOHobj
{
public:
    TOHop op;
    int num;
    Pole start, goal, tmp;

    //DOTOH operation constructor
    TOHobj(int n,Pole s, Pole g, Pole t)
    {
	op = DOTOH; num = n;
	start = s; goal = g; tmp = t;
    }
};

    //DOMOVE operation constructor
    TOHobj(Pole s, Pole g)
    {
	op = DOMOVE; start = s; goal = g;
    };

    void TOH(int n, Pole start, Pole goal, Pole tmp, Stack<TOHobj*>& S)
    {
	S.push(new TOHobj(n, start, goal, tmp));
	TOHobj* t;
	while (S.length()>0)
	{
	    t=S.pop();
	    if (t->op == DOMOVE)
		move(t->start, t->goal);
	    else if (t->num > 0)
	    {
		int num = t->num;
		Pole tmp = t->tmp;
		Pole goal = t->goal;
		Pole start = t->start;
		S.push(new TOHobj(num-1, tmp, goal, start));
		S.push(new TOHobj(start, goal));
		S.push(new TOHobj(num-1, start, tmp,goal));
	    }
	    delete t;
	}
    }
