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

//  - A B C D -> A B - C D -> A B - - D
char Josephus(Queue<char> &q, int k)
{
	q.Print();

	while (q.Size() != 1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			char temp = q.Front();
			q.Dequeue();
			q.Enqueue(temp);
		}

		q.Print();
		q.Dequeue();
		q.Print();
	}

	return q.Front();
}

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
	print_arr(arr, n);

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

	print_arr(arr, n);

	Josephus3(arr + 1, n - 1, k);

	return arr[n - 1];
	

}