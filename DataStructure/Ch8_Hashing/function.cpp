#include "function.h"

void ArrPrint(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int InterpolationSearch(int arr[], int low, int high, int x)
{
	if (low > high)
	{
		return -1;
	}

	if ((arr[high] - arr[low]) == 0)
	{
		if (arr[high] == x)
		{
			return high;
		}
		else
		{
			return -1;
		}
	}

	int pos = ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]) + low;

	if (pos > high || pos < low)
	{
		return -1;
	}

	if (arr[pos] == x)
	{
		return pos;
	}
	else if (arr[pos] < x)
	{
		return InterpolationSearch(arr, pos + 1, high, x);
	}
	else if (arr[pos] > x)
	{
		return InterpolationSearch(arr, low, pos - 1, x);
	}
	else
	{
		return -1;
	}
}

int InterpolationSearch2(int arr[], int size, int x)
{
	int low = 0;
	int high = size - 1;

	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (arr[low] == arr[high])
		{
			if (arr[low] == x)
			{
				return low;
			}
			else
			{
				return -1;
			}
		}

		int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

		if (arr[pos] == x)
		{
			return pos;
		}
		else if (arr[pos] < x)
		{
			low = pos + 1;
		}
		else
		{
			high = pos - 1;
		}
	}

	return -1;
}

int SequentialSearch(int arr[], int start, int stop, int x)
{
	for (int i = start; i <= stop; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}


IndexTable::IndexTable(int arr[], int size, int m)
{
	if (size <= 0 || m <= 0 || m > size)
	{
		ptr = nullptr;
		return;
	}

	ptr = new Index_key[m];

	int j = 0;

	for (int i = 0; i < m; i++)
	{
		ptr[i].index = j;
		ptr[i].key = arr[j];
		j += size / m;
	}
}

IndexTable::~IndexTable()
{
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
}

int IndexSearch(int arr[], int size, int m, int x)
{
	if (x < arr[0] || x > arr[size - 1])
	{
		return -1;
	}

	IndexTable itb(arr, size, m);

	for (int i = 0; i < m; i++)
	{
		if (itb.ptr[i].key == x)
		{
			return itb.ptr[i].index;
		}
	}
	
	int i = 0;

	for (; i < m - 1; i++)
	{
		if (itb.ptr[i].key < x && itb.ptr[i + 1].key > x)
		{
			break;
		}
	}

	//std::cout << i << std::endl;

	if (i == m - 1)
	{
		int start = itb.ptr[i].index;
		int stop = size - 1;

		return SequentialSearch(arr, start, stop, x);
	}

	int start = itb.ptr[i].index;
	int stop = itb.ptr[i + 1].index;

	return SequentialSearch(arr, start, stop, x);

}

int IndexSearch2(int arr[], int size, int m, int x)
{
	if (size <= 0 || m <= 0 || m > size)
	{
		return -1;
	}

	if (x < arr[0] || x > arr[size - 1])
	{
		return -1;
	}

	IndexTable itb(arr, size, m);

	int i = 0;

	while (i < m - 1 && itb.ptr[i + 1].key <= x)
	{
		i++;
	}

	int start = itb.ptr[i].index;
	int stop;

	if (i == m - 1)
	{
		stop = size - 1;
	}
	else
	{
		stop = itb.ptr[i + 1].index - 1;
	}

	return SequentialSearch(arr, start, stop, x);
}