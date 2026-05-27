#include "myheader.h"

using namespace std;
    

int main()
{
    const int size = 8;
    int arr[size] = { 6,2,4,6,7,8,8,9 };
    

    sort_(arr, 8);

    cout << std::boolalpha;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << check_sort(arr, 8) << endl;
    
    int arr1[3];
  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arr1[0] = i;
                arr1[1] = j;
                arr1[2] = k;

                sort2(arr1, 3);

                for (int p = 0; p < 3; p++)
                {
                    cout << arr1[p] << " ";
                }
                cout << check_sort(arr1, 3) << endl;


            }
        }
    }


    
        



    return 0;
}

