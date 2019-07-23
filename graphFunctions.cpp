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

void graph::printConnections(int theNode)
{
	cout << "[" << theNode << "]";
	printConnections(table[theNode]);
	cout << " ---> NULL" << endl;
}

void graph::printConnections(node* theNode)
{
	if (!theNode)
		return;
	cout << " -" << theNode -> weight << "-> [" << theNode -> connection << "]";
	printConnections(theNode -> next);
}



//adds a connection
bool graph::addEdge(node* & edge, int to, int weight)
{
	if (!edge) 
	{
		edge = new node;
		edge -> connection = to;
		edge -> weight = weight;
		edge -> next = NULL;
		return true;
	}
	else
		return addEdge(edge -> next, to, weight);
}

bool graph::addEdge(int from, int to, int weight)
{
	if ((from < 0 || from >= SIZE) || (to < 0 || to >= SIZE))
		return false;
	bool value = addEdge(table[from], to, weight);
	//value = value && addEdge(table[to], from, weight);	//comment out to keep directed
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