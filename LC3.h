#include <iostream>
using namespace std;

const int defMaxListSize = 10; // Default maximum list size
typedef int DataType;

class List
{
public:
	// Constructor
	List(int maxNumber = defMaxListSize) throw (bad_alloc);
	// Destructor
	~List();
	// List manipulation operations
	void insert(const DataType &newDataItem) // Insert after cursor
		throw (logic_error);
	void remove() throw (logic_error); // Remove data item
	void replace(const DataType &newDataItem) // Replace data item
		throw (logic_error);
	void clear(); // Clear list
	// List status operations
	bool isEmpty() const; // List is empty
	bool isFull() const; // List is full
	// List iteration operations
	void gotoBeginning() throw (logic_error); // Go to beginning
	void gotoEnd() throw (logic_error); // Go to end
	bool gotoNext() throw (logic_error); // Go to next data item
	bool gotoPrior() throw (logic_error); // Go to prior data item
	DataType getCursor() const throw (logic_error); // Return data item
	// Output the list structure — used in testing/debugging
	void showStructure() const;
private:
	// Data members
	int maxSize,
		size, // Actual number of data item in the list
		cursor; // Cursor array index
	DataType *dataItems; // Array containing the list data item
};
