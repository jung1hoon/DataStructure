#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"
//#include <vector>
#include "vector.h"
#include "Matrix.h"
#include "Array2D.h"

using namespace std;


int main()
{
	Array2D arr1(2, 3);

	arr1.SetValue(0, 0, 0);
	arr1.SetValue(0, 1, 1);
	arr1.SetValue(0, 2, 2);
	arr1.SetValue(1, 0, 3);
	arr1.SetValue(1, 1, 4);
	arr1.SetValue(1, 2, 5);

	Array2D arr2 = arr1;

	Array2D arr3 = arr1.Add(arr1);

	Array2D arr4 = arr3.Transpose();

	arr1.print();
	cout << endl;

	arr2.print();
	cout << endl;

	arr3.print();
	cout << endl;

	arr4.print();
	cout << endl;

	cout << arr3.GetValue(1, 2) << " " << arr4.GetValue(2, 1) << endl;

	return 0;
}

