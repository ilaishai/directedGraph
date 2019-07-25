#include <cstring>

using namespace std;


struct queueNode
{
	int vertex;
	queueNode* next;
};


class queue
{
	public:
		queue();
		~queue();
		void enqueue(int vertex);
		int dequeue();
		void displayAll();
		bool isFull();
	private:
		queueNode* rear = NULL;
		queueNode* front = NULL;
		
};
