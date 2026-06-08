#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"
//#include <vector>
#include "vector.h"
#include "Matrix.h"
#include "Array2D.h"
#include "SparseMatrix.h"


using namespace std;


int main()
{
	SparseMatrix a(3,4,6);

	a.SetValue(0, 1, 3);
	a.SetValue(1, 3, 4);
	a.SetValue(0, 2, 5);
	a.SetValue(2, 3, 3);
	a.SetValue(0, 0, 2);
	a.SetValue(2, 1, 6);

	a.PrintTerms();

	a.Print();

	cout << a.GetValue(2, 3) << endl;

	SparseMatrix b = a.Transpose();

	b.PrintTerms();
	b.Print();

	cout << b.GetValue(3, 2) << endl;

	return 0;
}

