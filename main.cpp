#include <iostream>
#include <cstring>
#include "graphADT.h"
#include "queueADT.h"
#include "stackADT.h"

using namespace std;


int main()
{
	graph directedGraph;
	queue tempQueue;
	stack tempStack;
	int response = 1;

	cout << "This is a program to work with a directed graph. Use the menu below for assistance." << endl;	
	while (response)
	{
		int input2 = 0;
		int input1 = 0;
		int weight = 0;
		int temp = 0;
		queueNode* tempQueueNode;
		stackNode* tempStackNode;


		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\n0-To quit\n1-To display the graph connections\n2-To add a connection\n3-Check for a connection"
			<< "\n4-Traverse\n5-Enqueue item to the queue\n6-Dequeue from front\n7-Dispaly all queue"
			<< "\n9-Push an item on the stack\n10-Pop an item from the stack\n11-Display all in the stack\n" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


		//only cases 1-4 are crucial for the directed graph algorithm. The rest are used for testing
		//the different data structures used in the algorithm.
		switch (response)
		{
			case 0:
				return 0;
			case 1:
				directedGraph.printConnections();
				break;
			case 2:
				cout << "\nEnter the node from which you want to stretch the connection: ";
				cin >> input1;
				cin.ignore(100, '\n');
				cout << "\nEnter the node to which you want to connect: ";
				cin >> input2;
				cin.ignore(100, '\n');
				cout << "\nEnter the connection weight: ";
				cin >> weight;
				cin.ignore(100, '\n');

				directedGraph.addEdge(input1, input2, weight, false);
				break;

			case 3:
				cout << "\nEnter a value you want to check a connection for: ";
				cin >> input1;
				cin.ignore(100, '\n');
				cout << "\nEnter the connection you're looking for: ";
				cin >> input2;
				cin.ignore(100, '\n');
				cout << "\nThe connection exists: " << boolalpha << directedGraph.thereExists(input1, input2) << endl;
				break;
			case 4:
				cout << "\nEnter the starting location: ";
				cin >> input1;
				cin.ignore(100, '\n');
				cout << "\nEnter the destination you would like to reach: ";
				cin >> input2;
				cin.ignore(100, '\n');
				temp = directedGraph.traversal(input1, input2);
				cout << "\nThe path was found: " << temp << endl;
				break;
			case 5:
				cout << "\nEnter a value you want to enqueue: ";
				cin >> input1;
				cin.ignore(100, '\n');
				cout << "\nEnter the weight of the value: ";
				cin >> input2;
				cin.ignore(100, '\n');
				tempQueue.enqueue(input1, input2);
				break;
			case 6:
				tempQueueNode = tempQueue.dequeue();	
				cout << "Vertex: " << tempQueueNode -> vertex << " Cumulative Weight: " << tempQueueNode -> cumulativeWeight << endl;
				delete tempQueueNode;
				break;
			case 7:
				tempQueue.displayAll();
				break;
			case 8:
				cout << "\nThe queue is empty: " << boolalpha << tempQueue.isFull() << endl;
				break;

			case 9:
				cout << "\nEnter a value you want to push: ";
				cin >> input1;
				cin.ignore(100, '\n');
				cout << "\nEnter the weight of the value: ";
				cin >> input2;
				cin.ignore(100, '\n');
				tempStack.push(input1);
				break;

			case 10:	
				tempStackNode = tempStack.pop();	
				cout << "Vertex: " << tempStackNode -> vertex << endl;
				delete tempStackNode;
				break;

			case 11:
				tempStack.displayAll();
				break;
		}
	}
	return 0;
}
