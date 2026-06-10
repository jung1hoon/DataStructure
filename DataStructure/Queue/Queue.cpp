#include "../shared/queue.h"
#include "Josephus.h"

//Josephus

void print_arr(char arr[], int size)
{
	for (int i = 0; i < size ; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


//char Josephus(Queue<char> q, int k)
//{
//	int n = q.Size();
//	int start = (q.front() + 1) % q.Capacity();
//
//	for (int i = 0; i < length; i++)
//	{
//
//	}
//
//}

// A B C D
char Josephus2(char arr[], int n, int k)
{
	char temp;
	int first_index = 0;
	int size = n;

	while (first_index != n - 1)
	{

		print_arr(arr + first_index, size);

		for (int j = 0; j < k - 1; j++)
		{
			temp = arr[first_index];

			for (int i = first_index; i < n - 1; i++)
			{
				arr[i] = arr[i + 1];
			}

			arr[n - 1] = temp;
		}

		print_arr(arr + first_index, size);

		first_index++;
		size--;
	}

	print_arr(arr + first_index, size);

	return arr[first_index];

}

char Josephus3(char * arr, int n, int k)
{
	if (n == 1)
	{
		return arr[n - 1];
	}


	char temp;

	for (int j = 0; j < k - 1; j++)
	{
		temp = arr[0];

		for (int i = 0; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		arr[n - 1] = temp;
	}

	Josephus3(arr + 1, n - 1, k);

	return arr[n - 1];
	

}