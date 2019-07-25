#include "graphADT.h"
#include "queueADT.h"
#include <cstring>

using namespace std;

int graph::traversal(int start, int dest)
{
	queue priorityQueue;
	bool found = false;
	int countVisited = 0;
	bool* verticesVisited = new bool[SIZE];
	for (int i = 0; i < SIZE; ++i)
		verticesVisited[i] = 0;

	priorityQueue.enqueue(start);
	while (priorityQueue.isFull() && !found)
	{
		int now = priorityQueue.dequeue();
		node* current = table[now];
		cout << "Working on " << now << endl;
		while (current && !found)
		{
			int neighbor = current -> connection;
			if (neighbor == dest)
				found = true;
			if (!verticesVisited[neighbor])
			{
				cout << "	checking out " << neighbor << endl;
				verticesVisited[neighbor] = true;
				priorityQueue.enqueue(neighbor);
			}
			current = current -> next;
		}
	}
	
	delete[] verticesVisited;

	if (found)
		return 1;
	else
		return 0;
}
