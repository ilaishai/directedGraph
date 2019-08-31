#include "graphADT.h"
#include "queueADT.h"
#include "stackADT.h"
#include <cstring>

using namespace std;

struct visitInfo
{
	int weight;
	int inducedBy;
};


void traverseArray(int current, int find, visitInfo* array, stack* pathOrder);

int graph::traversal(int start, int dest)
{
	queue priorityQueue;
	queue tempQueue;
	stack pathOrder;

	int smallestDistance = -1;
	int countVisited = 0;
	int totalWeight = 0;
	//bool* verticesVisited = new bool[SIZE];
	visitInfo* verticesVisited = new visitInfo[SIZE];


	for (int i = 0; i < SIZE; ++i)
		verticesVisited[i].weight = -1;

	priorityQueue.enqueue(start, 0);
	tempQueue.enqueue(start, 0);
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
			if (verticesVisited[neighbor].weight == -1 || verticesVisited[neighbor].weight > totalWeight)
			{
				cout << "	checking out " << neighbor << " induced by " << nowNode -> vertex << endl;
				verticesVisited[neighbor].weight = totalWeight;
				verticesVisited[neighbor].inducedBy = nowNode -> vertex;
				priorityQueue.enqueue(neighbor, totalWeight);
				tempQueue.enqueue(neighbor, totalWeight);

			}
			if (neighbor == dest)
			{
				if (smallestDistance == -1 || smallestDistance > totalWeight)
					smallestDistance = totalWeight;
			}
			current = current -> next;
		}
		delete nowNode;
	}
	tempQueue.displayAll();

	if (smallestDistance != -1)
		traverseArray(dest, start, verticesVisited, &pathOrder);
	
	pathOrder.displayAll();
	
	delete[] verticesVisited;
	return smallestDistance;
}


//the array keeps track of the verteces, as well as the cheapest vertex
//leading there. This goes backwards from the dest through the start and 
//adds it to a stack
void traverseArray(int current, int find, visitInfo* array, stack* pathOrder)
{
	if (current == find)
		pathOrder -> push(current);
	else
	{
		pathOrder -> push(current);
		traverseArray(array[current].inducedBy, find, array, pathOrder);
	}
}
