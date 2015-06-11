//a simple payroll entry with ID, name, address fields
class Payroll
{
private:
    int ID;
    string name;
    string address;

public:
    //constructor
    Payroll(int inID, string inname, string inaddr)
    {
	ID = inID;
	name = inname;
	address = inaddr;
    }

    ~Payroll() {} 					//destructor

    //local data member access functions
    int getID() {return ID;}
    string getName() {return name;}
    string getaddr() {return address;}
};
