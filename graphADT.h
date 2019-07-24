#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	int connection;
	int weight;
	node* next;
};


class graph
{
	public:
		graph();
		~graph();
		bool existsConnection(int from, int to);

		void printConnections();
		void printConnections(int theNode);	
		bool thereExists(int dest, int connection);
		bool addEdge(int from, int to, int weight, bool twoWay);

		int traversal(int start, int dest);
	private:
		bool addEdge(node* & from, int to, int weight, bool twoWay);
		void delRecursive(node* head);
		void printConnections(node* theNode);

		int traversal(int start, int dest, int path);

		const int SIZE = 10;
		node** table = NULL;
};
