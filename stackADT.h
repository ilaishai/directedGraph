#include <cstring>

using namespace std;

struct stackNode
{
	int vertex;
	stackNode* next;
};


class stack
{
	public:
		stack();
		~stack();
		void push(int vertex);
		stackNode* pop();
		void displayAll();
	private:
		stackNode* top = NULL;
};
