#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"
//#include <vector>
#include "vector.h"
#include "Matrix.h"

using namespace std;


int main()
{
	Matrix<int> mtx1(2,3);

	mtx1.SetValue(0, 0, 0);
	mtx1.SetValue(0, 1, 1);
	mtx1.SetValue(0, 2, 2);
	mtx1.SetValue(1, 0, 3);
	mtx1.SetValue(1, 1, 4);
	mtx1.SetValue(1, 2, 5);

	Matrix<int> mtx2(mtx1);

	Matrix<int> mtx3 = mtx1.Add(mtx2);

	Matrix<int> mtx4 = mtx1.Transpose3();

	mtx1.print();
	cout << endl;

	mtx2.print();
	cout << endl;

	mtx3.print();
	cout << endl;

	mtx4.print();
	cout << endl;

	return 0;
}

