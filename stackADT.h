#include <cstring>

using namespace std;

struct stackNode
{
	int vertex;
	int cumulativeWeight;
	int previous;
	stackNode* next;
};


class stack
{
	public:
		stack();
		~stack();
		void push(int vertex, int cumulativeWeight, int previous);
		stackNode* pop();
		void displayAll();
	private:
		stackNode* top = NULL;
};
