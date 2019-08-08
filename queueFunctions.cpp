#include "queueADT.h"
#include <cstring>
#include <iostream>

using namespace std;


//constructor for the queue object
queue::queue()
{
	rear = NULL;
	front = NULL;
}


//destructor for the queue object
queue::~queue()
{
	queueNode* temp = NULL;
	while (front != rear)
	{
		temp = front -> next;
		delete front;
		front = temp;
		rear -> next = front;
	}
	delete front;
	front = NULL;
	rear = NULL;
}


//add an item at the end
void queue::enqueue(int vertex, int cumulativeWeight)
{
	if (!rear)
	{
		rear = new queueNode;
		rear -> vertex = vertex;
		rear -> cumulativeWeight = cumulativeWeight;
		front = rear;
		rear -> next = front;
	}
	else
	{
		queueNode* temp = new queueNode;
		temp -> vertex = vertex;
		temp -> cumulativeWeight = cumulativeWeight;
		rear -> next = temp;
		rear = rear -> next;
		rear -> next = front;
	}
}


queueNode* queue::dequeue()
{
	queueNode* returnedNode = new queueNode;
	if (!front)
	{
		returnedNode -> vertex = -1;
		returnedNode -> cumulativeWeight = -1;
	}
	else
	{
		queueNode* temp = NULL;
		int vertex = front -> vertex;
		int cumulativeWeight = front -> cumulativeWeight;

		returnedNode -> vertex = vertex;
		returnedNode -> cumulativeWeight = cumulativeWeight;
		if (front != rear)
		{
			temp = front -> next;
			delete front;
			front = temp;
			rear -> next = front;
		}
		else
		{
			delete front;
			front = NULL;
			rear = NULL;
		}
	}
	return returnedNode;
}


void queue::displayAll()
{
	if (front)
	{
		queueNode* current = front;
		do
		{
			cout << "Vertex: " << current -> vertex << " Cumulative Weight: " << current -> cumulativeWeight << endl;
			current = current -> next;
		} while (current != rear -> next);
	}
}

bool queue::isFull()
{
	if (front)
		return true;
	else
		return false;
}
