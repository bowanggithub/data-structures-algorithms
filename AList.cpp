template <typename E>					//Array-based list implementation
class AList : public List<E>
{
private:
    int maxSize;					//maximum size of list
    int listSize;					//number of list items now
    int curr;						//position of current element
    E* listArray					//Array holding the list elements

public:
    AList(int size=defaultSize)				//constructor
    {
	maxSize = size;
	listSize = curr =0;
	listArray = new E[maxSize];
    }

    ~AList() {delete [] listArray; }			//destructor

    void clear()					//reinitialize the list
    {
	delete [] listArray;				//remove the array
	listSize = curr = 0;				//reset the size
	listArray = new E[maxSize];			//recreate array
    }

    //insert "it" at current position
    void insert(const E& it)
    {
	Assert(listSize < maxSize, "List capacity exceed");
	for (int i=listSize; i>curr; i--)		//shift elements up
	    listArray[i] = listArray[i-1];		//to make room
	listArray[curr] = it;
	listSize++;					//increment list size
    }

    void append(const E& it)				//append "it"
    {
	Assert(listSize < maxSize, "List capacity exceeded");
	listArray[listSize++] = it;
    }

    //remove and return the current element
    E remove()
    {
	Assert((curr>=0) && (curr<listSize), "No element");
	E it = listArray[curr];				//copy the element
	for (int i=curr; i<listSize-1;i++)		//shift them down
	    listArray[i] = listArray[i+1];
	listSize--;					//decrement size
	return it;
    }
    
    void moveToStart() {curr = 0; }			//reset position
    void moveToEnd() {curr = listSize; }		//set at end
    void prev() {if (curr != 0) curr--; }		//back up
    void next() {if (curr < listSize) curr++; }		//next

    //return list Size
    int length() const {return listSize;}

    //return current position
    int currPos() const {return curr;}

    //set current list position to "pos"
    void moveToPos(int pos)
    {
	Assert((pos>=0)&&(curr<listSize), "No current element");
	return listArray[curr];
    }
};
