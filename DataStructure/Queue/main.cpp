#include "../shared/queue.h"
#include "Josephus.h"
#include "../shared/deque.h"
#include "postfix.h"

using namespace std;

int main()
{
	const char infix[] = "1+2*3";
	int size = sizeof(infix) / sizeof(infix[0]) - 1;
	Queue<char> q1;

	for (int i = 0; i < size; i++)
	{
		q1.Enqueue(infix[i]);
	}

	Queue<char> q2;

	InfixToPostfix(q1, q2);

	q2.Print();

	int r = EvalPostfix(q2);

	cout << r << endl;

	return 0;
}