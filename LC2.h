//ptlist.h
const int maxListSize = 3; // Default maximum list size

class Point
{
public:
	Point(float x0 = 0, float y0 = 0) // Constructor
	{
		x = x0; y = y0;
	}
	float x, y; // Point coordinates (can be accessed directly)
};

class PointList
{
public:
	// Constructor
	PointList();
	// List manipulation operations
	void append(Point newPoint); // Append point to list
	void clear(); // Clear list
	// List status operations
	bool isEmpty() const; // List is empty
	bool isFull() const; // List is full
	// List iteration operations
	void gotoBeginning(); // Go to beginning
	void gotoEnd(); // Go to end
	bool gotoNext(); // Go to next point
	bool gotoPrior(); // Go to prior point
	Point getCursor() const; // Return point
	// Output the list structure — used in testing/debugging
	void showStructure() const;

	bool isTraisTranslation(const PointList &otherList);
	void insertAtBeginning(Point newPoint);
private:
	// Data members
	int size, // Actual number of points in the list
		cursor; // Cursor index
	Point points[maxListSize]; // Array containing the points
};

PointList::PointList()
{
	size = 0;
	cursor = 1;
}

void PointList::append(Point newPoint)
{
	if (size != maxListSize)
	{
		points[size] = newPoint;
		size++;
		cursor++;
	}
}

void PointList::clear()
{
	size = 0;
	cursor = 0;
}

bool PointList::isEmpty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

bool PointList::isFull() const
{
	if (size == maxListSize)
		return true;
	else
		return false;
}

void PointList::gotoBeginning()
{
	cursor = 0;
}

void PointList::gotoEnd()
{
	cursor = size;
}

bool PointList::gotoNext()
{
	if (cursor < size - 1)
	{
		cursor++;
		return true;
	}
	else
		return false;
}

bool PointList::gotoPrior()
{
	if (cursor != 0)
	{
		cursor--;
		return true;
	}
	else
		return false;
}

Point PointList::getCursor() const
{
	if (size != 0)
		return points[cursor];
}

void PointList::showStructure() const
{
	if (size == 0)
		std::cout << "Empty" << std::endl;
	else
		for (int i = 0; i < size; i++)
			std::cout << "(" << points[i].x << ',' << points[i].y << ")" << std::endl;
}

bool PointList::isTraisTranslation(const PointList &otherList)
{
	if (size != otherList.size)
		return false;
	else
	{
		float dx, dy;
		dx = points[0].x - otherList.points[0].x;
		dy = points[0].y - otherList.points[0].y;
		for (int i = 0; i < size; i++)
		{
			if ((dx != points[i].x - otherList.points[i].x) || (dy != points[i].y - otherList.points[i].y))
				return false;
		}
		return true;
	}
}

void PointList::insertAtBeginning(Point newPoint)
{
	if (isFull())
	{
		for (int i = size; i > 0; i--)
		{
			points[i + 1] = points[i];
		}
		points[0] = newPoint;
	}
}
