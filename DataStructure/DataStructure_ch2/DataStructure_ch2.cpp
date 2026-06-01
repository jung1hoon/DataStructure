#include "Recur_func.h"
#include "mystring.h"

using namespace std;


int main()
{
	Mystring str1("Hello");
	Mystring str2(str1);
	Mystring str3;

	

	cout << str1.Insert(Mystring("World"), 1) << endl;


	return 0;
}

