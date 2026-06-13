#include "../shared/queue.h"
#include "Josephus.h"
#include "../shared/deque.h"

using namespace std;

int main()
{
	Deque<char> dq;

	dq.push_front('A');

	dq.Print();

	dq.push_front('B');

	dq.Print();

	dq.push_front('C');

	dq.Print();

	dq.push_back('D');

	dq.Print(); // C B A D

	dq.pop_front();

	dq.Print(); // B A D

	dq.pop_back();

	dq.Print(); // B A 

	return 0;
}