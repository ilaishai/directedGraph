#include <cstring>
#include "graphADT.h"

using namespace std;


//constructor for the object
graph::graph()
{
	table = new node*[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		table[i] = NULL;
	}
}

//recursively remove the given chain
void graph::delRecursive(node* head)
{
	if (!head)
		return;
	delRecursive(head -> next);
	delete head;
}
//destructor for the object
graph::~graph()
{
	for (int i = 0; i < SIZE; ++i)
		delRecursive(table[i]);
	delete [] table;
}



//prints the connections of the graph
void graph::printConnections()
{
	cout << "\n";
	for (int i = 0; i < SIZE; ++i)
		printConnections(i);
}

//parent function for printing
void graph::printConnections(int theNode)
{
	cout << "[" << theNode << "]";
	printConnections(table[theNode]);
	cout << " ---> NULL" << endl;
}

//traverse through the chain recursively printing it out
void graph::printConnections(node* theNode)
{
	if (!theNode)
		return;
	cout << " -" << theNode -> weight << "-> [" << theNode -> connection << "]";
	printConnections(theNode -> next);
}



//adds a connection
bool graph::addEdge(node* & edge, int to, int weight, bool twoWay)
{
	if (!edge) 
	{
		edge = new node;
		edge -> connection = to;
		edge -> weight = weight;
		edge -> next = NULL;
		return true;
	}
	else if (edge -> next && edge -> next -> weight > weight)
	{
		node* temp = new node;
		temp -> connection = to;
		temp -> weight = weight;
		temp -> next = edge -> next;
		edge -> next = temp;
		return true;
	}
	else
		return addEdge(edge -> next, to, weight, twoWay);
}

bool graph::addEdge(int from, int to, int weight, bool twoWay)
{
	if ((from < 0 || from >= SIZE) || (to < 0 || to >= SIZE))
		return false;

	if (table[from])
	{
		if (table[from] -> weight > weight)
		{
			node* temp = table[from];
			table[from] = new node;
			table[from] -> connection = to;
			table[from] -> weight = weight;
			table[from] -> next = temp;
			return true;
		}
	}
	bool value = addEdge(table[from], to, weight, twoWay);

	//keep the graph two way or directed
	if (twoWay)
		value = value && addEdge(to, from, weight, false);
	return value;
}



//TODO: SET UP A BUNCH OF CONVENICENCE FUNCTIONS FOR THE SAKE OF EASIER WORK LATER
//TODO: MAKE A 'EXISTS CONNECTION' FUNCTION
//TODO: AUTOMATICALLY MAKE CONNECTIONS TWO WAY
//

bool graph::thereExists(int dest, int connection)
{
	node* current = table[dest];
	while (current)
	{
		if (current -> connection == connection)
			return true;
		current = current -> next;
	}
	return false;
}
