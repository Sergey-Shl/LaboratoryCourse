// For this example, set DataType to “int” in listarr.h,
#include <iostream>
#include "List.h" // Include the class declaration file
using namespace std;
void main()
{
	int *a = new int[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;

	int s = 0;
	for (int i = 0; i < 10; i++)
		s += a[i];

	List samples(100); // Set of samples
	int newSample, // Input sample
		total = 0; // Sum of the input samples
	// Read in a set of samples from the keyboard.
	cout << "Enter list of samples(end with eof) : ";
	while (cin >> newSample)
		samples.insert(newSample);
	// Sum the samples and output the result.
	if (!samples.isEmpty()) // Verify that list has data
	{
		samples.gotoBeginning(); // Go to beginning of list
		do
			total += samples.getCursor(); // Add element to running sum
		while (samples.gotoNext()); // Go to next element (if any)
	}
	cout << "Sum is " << total << endl;
	system("pause");
}
