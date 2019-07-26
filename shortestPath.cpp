#include "graphADT.h"
#include "queueADT.h"
#include <cstring>

using namespace std;

int graph::traversal(int start, int dest)
{
	queue priorityQueue;
	int smallestDistance = -1;
	int countVisited = 0;
	int totalWeight = 0;
	bool* verticesVisited = new bool[SIZE];
	for (int i = 0; i < SIZE; ++i)
		verticesVisited[i] = 0;

	priorityQueue.enqueue(start, 0);
	while (priorityQueue.isFull())
	{
		queueNode* nowNode = priorityQueue.dequeue();
		node* current = table[nowNode -> vertex];
		cout << "Working on " << nowNode -> vertex << " (" << nowNode -> cumulativeWeight << ")" << endl;
		while (current)
		{
			int neighbor = current -> connection;
			int currentWeight = current -> weight;

			totalWeight = nowNode -> cumulativeWeight + currentWeight;
			if (neighbor == dest)
			{
				if (smallestDistance == -1 || smallestDistance < totalWeight)
					smallestDistance = totalWeight;
			}
			if (!verticesVisited[neighbor])
			{
				cout << "	checking out " << neighbor << endl;
				verticesVisited[neighbor] = true;
				priorityQueue.enqueue(neighbor, totalWeight);
			}
			current = current -> next;
		}
		delete nowNode;
	}
	
	delete[] verticesVisited;
	return smallestDistance;
}
