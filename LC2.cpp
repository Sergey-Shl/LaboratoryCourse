#include <iostream>
#include "ptlist.h"

using namespace std;

void main()
{
	PointList polygon; // Set of vertices for a polygon
	Point vertex; // Vertex
	// Read in the polygon’s vertices.
	cout << "Enter the polygon’s vertices(end with eof) : ";
	while (!polygon.isFull())
	{
		cin >> vertex.x >> vertex.y;
		polygon.append(vertex);
	}
	// Output the vertices one per line.
	if (!polygon.isEmpty())
	{
		polygon.gotoBeginning(); // Go to beginning of list
		do
		{
			vertex = polygon.getCursor();
			cout << "(" << vertex.x << ", "
				<< vertex.y << ")" << endl;
		} while (polygon.gotoNext()); // Go to next point (if any)
	}

	system("pause");
}
