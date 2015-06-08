class GameEntry					//a game score entry
{
public:
    GameEntry(const string& n="", int s=0);	//constructor
    string getName() const;			//get player's name
    int getScore() const;			//get player's score
private:
    string name;				
    int score;
};
