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