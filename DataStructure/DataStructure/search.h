#pragma once
#include <iostream>

// n을 count하는 함수
int count(int arr[], int size, int n);

// c라는 문자 개수 반환
int char_count(char* arr, char c);

// n을 찾는 함수
int linearsearch(int arr[], int size, int n);

// 정렬된 배열에서 n 개수
int sorted_count(int arr[], int size, int n);

// 문자와 그 문자 개수 출력 ex) a3b4d6...
void char_n_number(int table[], int size);
// 테스트용 함수
void search_test1(char arr[], int count_table[]);




template<typename T>
int linearsearch_tp(T arr[], int size, T n)
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


template<typename T>
int sorted_count_tp(T arr[], int size, T n)
{
	int start = linearsearch_tp<T>(arr, size, n);
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

// 정렬된 char array에서 문자와 그 문자의 개수 출력
void sorted_char_num1(char arr[], int size);
void sorted_char_num2(char arr[], int size);


//BinarySearch
int MyBinarySearch(int arr[], int size, int n); 
int BinarySearch(int arr[], int size, int n); // 일반적인 정석