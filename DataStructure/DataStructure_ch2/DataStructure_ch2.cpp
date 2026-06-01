#include "Recur_func.h"
#include "mystring.h"

using namespace std;


int main()
{
	Mystring str1("Hello");
	Mystring str2(str1);
	Mystring str3("HHHH");

	str3 = str1;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;


	return 0;
}

