#include "sorting.h"

using namespace std;

int main()
{
	int arr[] = { 3,5,2,6,7,9,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);
	cout << endl;

	//InsertionSort(arr, n, n / 2);
	ShellSort(arr, n);
	Print(arr, n);
	cout << endl;

	return 0;
}