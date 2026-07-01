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

