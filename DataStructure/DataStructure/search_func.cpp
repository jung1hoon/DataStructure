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


void sorted_char_num1(char arr[], int size)
{
	for (char i = 'a'; i <= 'z'; i++)
	{
		int start_index = linearsearch_tp(arr, size, i);
		int count = 0;

		if (start_index == -1)
		{
			continue;
		}

		for (int j = start_index; j < size - 1; j++)
		{
			if (arr[j] == i)
			{
				count++;
			}
			else
			{
				break;
			}
		}

		std::cout << i << count;
	}

}

void sorted_char_num2(char arr[], int size)
{
	int i = 0;
	int count = 0;
	char current = arr[i];
	

	for (; i < size ;)
	{
		if (arr[i] == current)
		{
			count++;
			i++;
		}
		else
		{
			std::cout << current << count;
			count = 0;
			current = arr[i];
		}
	}
}
