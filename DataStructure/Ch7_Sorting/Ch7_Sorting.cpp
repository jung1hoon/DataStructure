#include "sorting.h"

using namespace std;

int main()
{
	int arr[] = { 3,5,2,6,7,9,1 };
	const int n = sizeof(arr) / sizeof(arr[0]);
	//int merged[n];

	//Print(arr, n);
	//cout << endl;

	////InsertionSort(arr, n, n / 2);
	//ShellSort(arr, n);
	//Print(arr, n);
	//cout << endl;

	//MergeSort(arr, merged, 0, n - 1);
	//MergeSort2(arr, 0, n - 1);

	//QuickSort(arr, 0, n - 1);
	RadixSort(arr, n);


	Print(arr, n);

	return 0;
}