#include <iostream>
#include <cstring>
#include "graphADT.h"

using namespace std;

int main()
{
	graph directedGraph;
	int response = 1;

	cout << "This is a program to work with a directed graph. Use the menu below for assistance." << endl;	
	while (response)
	{
		int to = 0;
		int from = 0;
		int weight = 0;

		cout << "\n0-To quit\n1-To display the graph connections\n2-To add a connection\n3-Check for a connection" << endl;
		cin >> response;
		cin.ignore(100, '\n');

		switch (response)
		{
			case 0:
				return 0;
			case 1:
				directedGraph.printConnections();
				break;
			case 2:
				cout << "What node do you want to stretch a connection from?" << endl;
				cin >> from;
				cin.ignore(100, '\n');
				cout << "Which node do you want to connect it to?" << endl;
				cin >> to;
				cin.ignore(100, '\n');
				cout << "What is the weight of the connection?" << endl;
				cin >> weight;
				cin.ignore(100, '\n');

				directedGraph.addEdge(from, to, weight);
				break;

			case 3:
				cout << "Enter a value you want to check for a connection for" << endl;
				cin >> from;
				cin.ignore(100, '\n');
				cout << "Enter the connection you're looking for" << endl;
				cin >> to;
				cin.ignore(100, '\n');
				cout << "The connection exists: " << boolalpha << directedGraph.thereExists(from, to) << endl;
				break;
			case 4:
				cout << "Enter the starting location: ";
				cin >> from;
				cin.ignore(100, '\n');
				cout << "\nEnter the destination you would like to reach: " << endl;
				cin >> to;
				cin.ignore(100, '\n');
				cout << "The path was found: " << boolalpha << directedGraph.traversal(from, to) << endl;
				break;
		}
	}
	return 0;
}
