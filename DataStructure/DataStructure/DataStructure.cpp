#include "sort_header.h"
#include "search.h"

using namespace std;
    

int main()
{
    
    char arr[] = "abbdcsaggsadazzzfggbhaii";
    int size = sizeof(arr) / sizeof(arr[0]);
    int table[26] = { 0 };

   

    insertion_sort_tp(arr, size-1);
    print_arr(arr, size-1);
    sorted_char_num2(arr, size);


    return 0;
}

