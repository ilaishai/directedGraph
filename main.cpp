#include <iostream>
#include <cstring>
#include "graphADT.h"
#include "queueADT.h"

using namespace std;

int main()
{
	graph directedGraph;
	queue tempQueue;
	int response = 1;

	cout << "This is a program to work with a directed graph. Use the menu below for assistance." << endl;	
	while (response)
	{
		int to = 0;
		int from = 0;
		int weight = 0;
		int temp = 0;
		
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\n0-To quit\n1-To display the graph connections\n2-To add a connection\n3-Check for a connection"
			<< "\n4-Traverse\n5-Enqueue item to the queue\n6-Dequeue from front\n7-Dispaly all queue\n" << endl;
		cin >> response;
		cin.ignore(100, '\n');
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		switch (response)
		{
			case 0:
				return 0;
			case 1:
				directedGraph.printConnections();
				break;
			case 2:
				cout << "\nEnter the node from which you want to stretch the connection: ";
				cin >> from;
				cin.ignore(100, '\n');
				cout << "\nEnter the node to which you want to connect: ";
				cin >> to;
				cin.ignore(100, '\n');
				cout << "\nEnter the conneciton weight: ";
				cin >> weight;
				cin.ignore(100, '\n');

				directedGraph.addEdge(from, to, weight, false);
				break;

			case 3:
				cout << "\nEnter a value you want to check a connection for: ";
				cin >> from;
				cin.ignore(100, '\n');
				cout << "\nEnter the connection you're looking for: ";
				cin >> to;
				cin.ignore(100, '\n');
				cout << "\nThe connection exists: " << boolalpha << directedGraph.thereExists(from, to) << endl;
				break;
			case 4:
				cout << "\nEnter the starting location: ";
				cin >> from;
				cin.ignore(100, '\n');
				cout << "\nEnter the destination you would like to reach: ";
				cin >> to;
				cin.ignore(100, '\n');
				temp = directedGraph.traversal(from, to);
				cout << "\nThe path was found: " << boolalpha << temp << endl;
				break;
			case 5:
				cout << "\nEnter a value you want to enqueue: ";
				cin >> to;
				cin.ignore(100, '\n');
				tempQueue.enqueue(to);
				break;
			case 6:
				cout << tempQueue.dequeue() << endl;
				break;
			case 7:
				tempQueue.displayAll();
				break;
			case 8:
				cout << "\nThe queue is empty: " << boolalpha << tempQueue.isFull() << endl;
				break;
		}
	}
	return 0;
}
