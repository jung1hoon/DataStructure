#include "myheader.h"

swap_value& swap(int a, int b)
{
    swap_value s;
    int temp = a;
    a = b;
    b = temp;
    s.a = a;
    s.b = b;

    return s;
}

std::ostream& operator <<(std::ostream& out, swap_value& swap)
{
    out << swap.a << " " << swap.b;
    return out;
}

void sort_two_value_print(int a, int b)
{
    if (!check_two_sort(a, b))
    {
        My_swap(a, b);
    }

    print_check(a, b);
}


bool check_two_sort(int a, int b)
{
    if (a > b)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void print_check(int a, int b)
{
    std::cout << std::boolalpha;
    std::cout << a << " " << b << " "\
        << check_two_sort(a, b) << std::endl;
}


void swap_no_temp(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

//

bool check_sort(int* p, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        if (p[i] > p[i + 1]) 
        {
            return false;
        }
    }
    return true;
}

void sort_(int arr[], int size)
{
    int min_index;

    for (int i = 0; i < size-1; i++)
    {   
        min_index = i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        My_swap(arr[i], arr[min_index]);
    }
}


void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                My_swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

// 삽입 정렬
// 1 앞쪽부터 하나씩 정렬
// 2 arr[i] > arr[i+1] 이 생기면 arr[i+1]을 앞에 있는 것들과\
//   하나씩 비교하면서 정렬
// (5,4),6,2,1 -> (4,(5,3)),2,1 -> 3,4,(5,2),1 ...
void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                My_swap(arr[j - 1], arr[j]);
               
            }
            else
            {
                break;
            }
        }
    }
}