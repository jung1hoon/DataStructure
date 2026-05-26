#include "myheader.h"

using namespace std;
    

int main()
{
    int arr[3] = { 6,2,4 };

    sort_(arr, 3);

    cout << std::boolalpha;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " 
        << check_sort(arr, 3) << endl;
    



    return 0;
}

