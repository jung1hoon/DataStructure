#include "myheader.h"

using namespace std;
    

int main()
{
    int arr1[2] = { 0,0 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			print_check(arr1[0], arr1[1]);
			arr1[0]++;
		}

		arr1[1]++;
		arr1[0] = 0;
	}

	cout << "======================================" << endl;

	int arr2[2] = { 0,0 };

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			sort_two_value_print(arr2[0], arr2[1]);
			arr2[0]++;
		}

		arr2[1]++;
		arr2[0] = 0;
	}




    return 0;
}

