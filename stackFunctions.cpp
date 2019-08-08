#include "stackADT.h"
#include <cstring>
#include <iostream>

using namespace std;

stack::stack()
{
	top = NULL;
}

stack::~stack()
{
	while (top)
	{
		stackNode* temp = top -> next;
		delete top;
		top = temp;
	}
}

void stack::push(int vertex, int cumulativeWeight, int previous)
{
	stackNode* temp = top;
	top = new stackNode;

	top -> vertex = vertex;
	top -> cumulativeWeight = cumulativeWeight;
	top -> previous = previous;

	top -> next = temp;
}

stackNode* stack::pop()
{
	stackNode* returnedNode = new stackNode;
	if (top)
	{
		stackNode* temp = top -> next;
		returnedNode -> vertex = top -> vertex;
		returnedNode -> cumulativeWeight = top -> cumulativeWeight;
		returnedNode -> previous = top -> previous;

		if (top -> next)
			stackNode* temp = top -> next;
		delete top;
		top = temp;
	}
	else
	{
		returnedNode -> vertex = -1;
		returnedNode -> cumulativeWeight = -1;
		returnedNode -> previous = -1;
	}
	return returnedNode;
}

void stack::displayAll()
{
	stackNode* current = top;
	while (current)
	{
		cout << "Vertex: " << current -> vertex << endl;
		cout << "Cumulative weight: " << current -> cumulativeWeight << endl;
		cout << "Follows: " << current -> previous << endl;
		cout << endl;
		current = current -> next;
	}
}










