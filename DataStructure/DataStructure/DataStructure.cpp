#include "sort_header.h"
#include "search.h"

using namespace std;
    

int main()
{
    
    int arr[] = {0,1,2,4,3,5,8,7,6,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort2(arr, size);
    print_arr(arr, size);

    int n_index = BinarySearch(arr, size, 9);

    cout << n_index << endl;

    return 0;
}

