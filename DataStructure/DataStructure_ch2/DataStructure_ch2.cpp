#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"

using namespace std;


int main()
{

	SparsePolynomial p1;
	SparsePolynomial p2;

	p1.NewTerm(1, 0);
	p1.NewTerm(2, 1);
	p1.NewTerm(1, 2);
	p1.NewTerm(1, 3);

	p2.NewTerm(1, 0);
	p2.NewTerm(2, 1);
	p2.NewTerm(1, 4);

	SparsePolynomial p3 = p1.Add(p2);


	p1.Print();
	cout << endl;
	p2.Print();
	cout << endl;
	p3.Print();
	cout << endl;

	cout << p1.Eval(3) << " " << p2.Eval(2) << " " << p3.Eval(1) << endl;


	return 0;
}

