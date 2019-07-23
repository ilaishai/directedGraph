#include "graphADT.h"
#include <cstring>

using namespace std;

int graph::traversal(int start, int dest)
{
	int* path = 0;
	cout << "[" << start << "]" << endl;
	return traversal(start, dest, 0);
}

int graph::traversal(int start, int dest, int path)
{
	int result = 0;
	if (start == dest)
	{
		cout << "Arrived" << endl;
		return 1;
	}
	node* current = table[start];
	while (current)
	{
		result = traversal(current -> connection, dest, path + current -> weight);
		current = current -> next;
	}
	return result;


	/*
	node* current = table[start];
	while (current)
	{

		if (current -> connection == dest)
		{
			cout << "[" << current -> connection << "]" << endl;
			return 1;
		}

		if (current -> next)
		{
			int result = traversal(current -> next -> connection, dest, path + current -> weight);
			if (result)
				cout << current -> connection;
			return result;
		}
	}*/
}
