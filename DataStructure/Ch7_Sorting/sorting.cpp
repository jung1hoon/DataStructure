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

void Merge(int arr[], int merged[], int left, int mid, int right)
{
	int i, j, k, l;

	i = left;
	j = mid + 1;
	k = left;
	l = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			merged[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			merged[k] = arr[j];
			k++;
			j++;
		}
	}

	if (i > mid)
	{
		while (j <= right)
		{
			merged[k] = arr[j];
			k++;
			j++;
		}
	}
	else if (j > right)
	{
		while (i <= mid)
		{
			merged[k] = arr[i];
			k++;
			i++;
		}
	}

	for (; l <= right; l++)
	{
		arr[l] = merged[l];
	}
}

void Merge2(int arr[], int left, int mid, int right)
{
	int* merged = new int[right + 1];
	int i, j, k, l;

	i = left;
	j = mid + 1;
	k = left;
	l = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			merged[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			merged[k] = arr[j];
			k++;
			j++;
		}
	}

	if (i > mid)
	{
		while (j <= right)
		{
			merged[k] = arr[j];
			k++;
			j++;
		}
	}
	else if (j > right)
	{
		while (i <= mid)
		{
			merged[k] = arr[i];
			k++;
			i++;
		}
	}

	for (; l <= right; l++)
	{
		arr[l] = merged[l];
	}

	delete[] merged;
}


void MergeSort(int arr[], int merged[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, merged, left, mid);
		MergeSort(arr, merged, mid + 1, right);

		Merge(arr, merged, left, mid, right);
	}
}

void MergeSort2(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort2(arr, left, mid);
		MergeSort2(arr, mid + 1, right);

		Merge2(arr, left, mid, right);
	}
}