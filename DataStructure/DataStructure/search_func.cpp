#include "search.h"

int count(int arr[], int size, int n)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			count++;
		}
	}

	return count;
}

int linearsearch(int arr[], int size, int n)
{	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			return i;
		}
	}
	return -1;
}

// ex) 1 1 1 1 2 3 4
int sorted_count(int arr[], int size, int n)
{
	int start = linearsearch(arr, size, n);
	int count = 0;

	if (start == -1)
	{
		return 0;
	}

	while (start < size && arr[start] == n)
	{
		count++;
		start++;
	}

	return count;
}


int* search_indexes(int arr[],int size, int n)
{
	int count_ = count(arr, size, n);
	int index = 0;
	int* ptr = new int[count_];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			ptr[index] = i;
			index++;
		}
	}

	return ptr;
}

int char_count(char* arr, char c)
{
	int result = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == c)
		{
			result++;
		}
	}
	return result;
}


void char_n_number(int table[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] > 0)
		{
			std::cout << char(i + 97) << table[i];
		}
	}
	std::cout << std::endl;
}

void search_test1(char arr[], int count_table[])
{
	for (int i = 0; i < 26; i++)
	{
		count_table[i] = char_count(arr, char(i + 97));
	}

	char_n_number(count_table, 26);

}
