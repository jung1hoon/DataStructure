#pragma once
#include <iostream>



//swap
template<typename T>
void My_swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//print_int_array
void print_arr(int arr[], int size);
void print_arr(char arr[], int size);

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

//Template sort
template<typename T>
void insertion_sort_tp(T * arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        T temp = arr[i];
        int j = i;

        for (; j > 0; j--)
        {
            if (temp < arr[j - 1])
            {
                arr[j] = arr[j - 1];
               
            }
            else
            {
                break;
            }
        }
        arr[j] = temp;
        
        
    }
}





