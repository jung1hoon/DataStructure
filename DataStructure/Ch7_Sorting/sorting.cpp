#include "sorting.h"

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > key; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
}

void InsertionSort(int arr[], int n, int gap)
{
	for (int i = gap; i < n; i++)
	{
		int key = arr[i];
		int j = i;

		for (; j >= gap && arr[j - gap] > key; j -= gap)
		{
			arr[j] = arr[j - gap];
		}
		arr[j] = key;
	}
}

void ShellSort(int arr[], int n)
{
	int gap = n / 2;

	while (gap > 0)
	{
		InsertionSort(arr, n, gap);
		gap /= 2;
	}

	//for (int gap = n / 2; gap > 0; gap /= 2)
	//{
	//	InsertionSort(arr, n, gap);
	//}

}