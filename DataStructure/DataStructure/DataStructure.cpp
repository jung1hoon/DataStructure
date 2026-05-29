#include "sort_header.h"
#include "search.h"

using namespace std;
    

int main()
{
    //const int size = 5;
    //int arr[size] = { 3,1,5,2,4 };
    //

    //insertion_sort(arr, 5);

    //cout << std::boolalpha;

    //for (int i = 0; i < size; i++)
    //{
    //    cout << arr[i] << " ";
    //}
    //cout << check_sort(arr, 5) << endl;
    //
    //int arr1[3];
  
    //for (int i = 0; i < 3; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        for (int k = 0; k < 3; k++)
    //        {
    //            arr1[0] = i;
    //            arr1[1] = j;
    //            arr1[2] = k;

    //            bubble_sort(arr1, 3);

    //            for (int p = 0; p < 3; p++)
    //            {
    //                cout << arr1[p] << " ";
    //            }
    //            cout << check_sort(arr1, 3) << endl;


    //        }
    //    }
    //}

    //int arr2[5] = {1,2,3,4,5};

    //insertion_sort2(arr2, 5);

    const int size = 5;
    int arr[size] = {5,5,3,2,1};
    
    int result1 = count(arr, size, 3);
    int result2 = linearsearch(arr, size, 3);
    
    cout << result1 << endl;
    cout << result2 << endl;

    sort_(arr, size);
    print_arr(arr, size);

    cout << sorted_count(arr, size, 3) << endl;

    return 0;
}

