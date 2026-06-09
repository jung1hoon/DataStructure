#include "../shared/stack.h"

using namespace std;

int main()
{
	const char str[] = "Hello, World";
	int size = sizeof(str) / sizeof(str[0]) - 1;

	Stack<char> st1;

	for (int i = 0; i < size; i++)
	{
		st1.push(str[i]);
	}

	for (int i = 0; i < size ; i++)
	{
		cout << st1.Top();
		st1.pop();
	}

	cout << endl;


	return 0;
}