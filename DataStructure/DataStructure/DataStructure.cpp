#include "sort_header.h"
#include "search.h"

using namespace std;
    

int main()
{
    
    char arr[] = "abbdcsaggsada";
    int size = sizeof(arr) / sizeof(arr[0]);
    int table[26] = { 0 };

    //search_test1(arr, table);

    insertion_sort_tp(arr, size-1);
    print_arr(arr, size-1);

    int result = sorted_count_tp(arr, size, 'a');

    cout << result << endl;


    return 0;
}

