#pragma once
#include <iostream>

struct swap_value
{
	int a;
	int b;

};

std::ostream& operator <<(std::ostream& out, swap_value& swap);


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


//seletion sort
bool check_sort(int* p, int size);
void sort_(int arr[], int size);

//bubble_sort
void bubble_sort(int arr[], int size);

//insertion sort
void insertion_sort(int arr[], int size);
void insertion_sort2(int arr[], int size);

//print_int_array
void print_arr(int arr[], int size);
