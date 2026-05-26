#pragma once
#include <iostream>

struct swap_value
{
	int a;
	int b;
};


//swap
template<typename T>
void My_swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

swap_value& swap(int a, int b);


//check sorting(two values) and print
bool check_two_sort(int a, int b);
void print_check(int a, int b);

//sort, print
void sort_two_value_print(int a, int b);