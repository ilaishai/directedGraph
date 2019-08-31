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

void stack::push(int vertex)
{
	stackNode* temp = top;
	top = new stackNode;

	top -> vertex = vertex;
	top -> next = temp;
}

stackNode* stack::pop()
{
	stackNode* returnedNode = new stackNode;
	if (top)
	{
		stackNode* temp = top -> next;
		returnedNode -> vertex = top -> vertex;

		if (top -> next)
			stackNode* temp = top -> next;
		delete top;
		top = temp;
	}
	else
	{
		returnedNode -> vertex = -1;
	}
	return returnedNode;
}

void stack::displayAll()
{
	stackNode* current = top;
	while (current)
	{
		cout << current -> vertex << " -> ";
		current = current -> next;
	}
}
