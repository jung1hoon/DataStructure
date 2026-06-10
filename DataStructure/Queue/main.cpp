#include "../shared/queue.h"

int main()
{
	Queue<int> q(10);

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);

	q.Print();

	q.Dequeue();

	q.Print();

	q.Dequeue();

	q.Print();

	q.Dequeue();

	q.Print();

	return 0;
}