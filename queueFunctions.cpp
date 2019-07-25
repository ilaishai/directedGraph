#include "queueADT.h"
#include <cstring>
#include <iostream>

using namespace std;

queue::queue()
{
	rear = NULL;
	front = NULL;
}


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


void queue::enqueue(int vertex)
{
	if (!rear)
	{
		rear = new queueNode;
		rear -> vertex = vertex;
		front = rear;
		rear -> next = front;
	}
	else
	{
		queueNode* temp = new queueNode;
		temp -> vertex = vertex;
		rear -> next = temp;
		rear = rear -> next;
		rear -> next = front;
	}
}


int queue::dequeue()
{
	if (!front)
	{
		return -1;
	}
	else
	{
		queueNode* temp = NULL;
		int vertex = front -> vertex;

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
		return vertex;
	}

}


void queue::displayAll()
{
	if (front)
	{
		queueNode* current = front;
		do
		{
			cout << current -> vertex;
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
