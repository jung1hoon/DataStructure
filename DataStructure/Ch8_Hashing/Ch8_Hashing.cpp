#include "function.h"

class A
{
public:
	A();

	void print();
};

using namespace std;

int main()
{
	int arr[] = { 1, 3, 6, 9, 11, 15, 17, 24, 33, 42, 47 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//cout << InterpolationSearch(arr, 0, size - 1, 47) << endl;
	//cout << InterpolationSearch2(arr, size, 47) << endl;

	cout << IndexSearch2(arr, size, 3, 47) << endl;

	return 0;
}

