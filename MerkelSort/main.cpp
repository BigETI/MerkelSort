#include <iostream>
#include <chrono>
#include "Merkel.h"

using namespace std;
using namespace chrono;
using namespace Merkel;

/// <summary>
/// Print vector
/// </summary>
/// <param name="vec">Vector</param>
template <class _T> void print_vector(vector<typename _T> & vec)
{
	bool first(true);
	for (_T & item : vec)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			cout << ", ";
		}
		cout << item;
	}
	cout << endl;
}

/// <summary>
/// Main entry function
/// </summary>
/// <param name="argc">Argument count</param>
/// <param name="argv">Argument values</param>
/// <returns>Exit code</returns>
int main(int argc, char *argv[])
{
	vector<int> items;
	vector<int> result;
	time_point<chrono::system_clock> time_a, time_b;
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "Initializing items..." << endl;
	for (int i = 0; i < 100; i++)
	{
		items.push_back(rand());
	}
	cout << "Initialization done items..." << endl << "Starting to sort all values..." << endl;
	time_a = chrono::system_clock::now();
	result = Merkel::sort(items);
	time_b = chrono::system_clock::now();
	cout << "Sorting took " << (time_b - time_a).count() << " ns." << endl << "Original:" << endl;
	print_vector(items);
	cout << "Sorted:" << endl;
	print_vector(result);
	getchar();
	return 0;
}
