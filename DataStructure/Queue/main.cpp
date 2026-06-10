#include "../shared/queue.h"
#include "Josephus.h"

using namespace std;

int main()
{
	char arr[4] = { 'A', 'B', 'C', 'D' };

	char result = Josephus2(arr, 4, 3);

	cout << result << endl;

	return 0;
}