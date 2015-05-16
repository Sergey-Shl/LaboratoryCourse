#include "List.h"
#include <iostream>

using namespace std;

List::List(int maxNumber) throw (bad_alloc)
{
	maxSize = maxNumber;
	cursor = -1;
	size = 0;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < maxSize; i++)
		dataItems[i] = 0;
}

List::~List()
{
	delete[] dataItems;
}

void List::insert(const DataType &newDataItem) throw (logic_error)
{
	if (!isFull())
	{
		if (!isEmpty())
		{
			gotoNext();
			dataItems[cursor] = newDataItem;
			size++;
		} 
		else
		{
			cursor = 0;
			dataItems[cursor] = newDataItem;
			size++;
		}
	}
}

void List::remove() throw (logic_error)
{
	if (!isEmpty())
	{
		dataItems[cursor] = 0;
		size--;
		if (!isEmpty())
			if (!gotoNext())
				gotoBeginning();
	}
}

void List::replace(const DataType &newDataItem) throw (logic_error)
{
	dataItems[cursor] = newDataItem;
}

void List::clear()
{
	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = 0;
	}
	size = 0;
	cursor = -1;
}

bool List::isEmpty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

bool List::isFull() const
{
	if (size == maxSize)
		return true;
	else
		return false;
}

void List::gotoBeginning() throw (logic_error)
{
	if (!isEmpty())
		cursor = 0;
}

void List::gotoEnd() throw (logic_error)
{
	if (!isEmpty())
		cursor = maxSize - 1;
}

bool List::gotoNext() throw (logic_error)
{
	if (!isEmpty())
		if (cursor != maxSize - 1)
		{
			cursor++;
			return true;
		}
		else
			return false;
}

bool List::gotoPrior() throw (logic_error)
{
	if (!isEmpty())
		if (cursor != 0)
		{
			cursor--;
			return true;
		}
		else
			return false;
}

DataType List::getCursor() const throw (logic_error)
{
	if (!isEmpty())
		return dataItems[cursor];
}

void List::showStructure() const
{
	for (int i = 0; i < maxSize; i++)
	{
		cout << dataItems[i] << endl;
	}
}
