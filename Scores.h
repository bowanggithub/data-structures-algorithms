class Scores				//stores game high scores
{
public:
    Scores(int maxEnt = 10);		//constructor
    ~Scores();				//destructor
    void add(const GameEntry& e);	//add a game entry
    GameEntry remove(int i)		//remove a game entry
        throw(IndexOutOfBounds);
private:
    int maxEntries;			//maximum number of entries
    int numEntries;			//actual number of entries
    GameEntry* entries;			//array of game entries
};
