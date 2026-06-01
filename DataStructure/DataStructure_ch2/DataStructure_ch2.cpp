#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"

using namespace std;


int main()
{
	Polynomial poly;
	Polynomial poly2;

	poly.NewTerm(1.0f, 0);
	poly.NewTerm(2.0f, 1);
	poly.NewTerm(1.0f, 2);
	poly2.NewTerm(1.0f, 2);
	poly2.NewTerm(1.0f, 0);

	poly.Print();
	poly2.Print();

	cout << poly.MaxDegree() << endl;
	cout << poly2.MaxDegree() << endl;

	cout << poly.Eval(0) << endl;
	cout << poly.Eval(1) << endl;
	cout << poly.Eval(2) << endl;

	Polynomial add_poly = poly.Add(poly2);
	Polynomial mult_poly = poly.Mult(poly2);

	add_poly.Print();
	mult_poly.Print();

	cout << add_poly.MaxDegree() << endl;
	cout << mult_poly.MaxDegree() << endl;



	return 0;
}

