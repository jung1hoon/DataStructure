#include "Recur_func.h"


int RecurSum(int * arr, int size)
{
	if (size <= 0)
	{
		return 0;
	}
	else
	{
		return arr[size - 1] + RecurSum(arr, size - 1);
	}
}

//1 1 2 3 5 8 ...
int Fibo_Recur(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	return Fibo_Recur(n - 2) + Fibo_Recur(n - 1);
}

int Fibo_itr(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		int result = 0;
		int a1 = 1, a2 = 1;

		for (int i = 0; i < n-2; i++)
		{
			result = a1 + a2;
			a1 = a2;
			a2 = result;
		}

		return result;
	}
}

// 1 1 2 3 5 8 ... 
int Fibo_da(int n)
{
	if (n >= 1)
	{
		int* ptr = new int[n];
		int result = 0;

		if (n >= 3)
		{
			ptr[0] = 1;
			ptr[1] = 1;

			for (int i = 0; i < n - 2; i++)
			{
				ptr[i + 2] = ptr[i] + ptr[i + 1];
			}

			result = ptr[n - 1];
			delete[] ptr;
			return result;

		}
		else if (n == 1 || n == 2)
		{
			delete[] ptr;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int Recur_BinarySearch(int* arr, int left_index, int right_index, int n)
{
	int left = left_index;
	int right = right_index;

	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == n)
		{
			return middle;
		}
		else if (arr[middle] > n)
		{
			return Recur_BinarySearch(arr, left_index, middle - 1, n);
		}
		else
		{
			return Recur_BinarySearch(arr, middle + 1, right_index, n);
		}
	}
	else
	{
		return -1;
	}
}