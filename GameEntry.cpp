GameEntry::GameEntry(const string& n, int s)
    : name(n), score(s) {}

string GameEntry::getName() const {return name};
int GameEntry::getScore() const {return score;}
