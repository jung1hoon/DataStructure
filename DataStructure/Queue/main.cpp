#include "../shared/queue.h"
#include "Josephus.h"

using namespace std;

int main()
{
	char arr[4] = { 'A', 'B', 'C', 'D' };

	char result = Josephus3(arr, 4, 3);

	cout << result << endl;

	//Queue<char> q(5);

	//for (int i = 0; i < 4; i++)
	//{
	//	q.Enqueue('A' + i);
	//}



	//char result = Josephus(q, 3);

	//cout << result << endl;

	return 0;
}