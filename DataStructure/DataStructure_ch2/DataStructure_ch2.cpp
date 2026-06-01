#include "Recur_func.h"
#include "mystring.h"

using namespace std;


int main()
{
	Mystring str1("Hello");
	Mystring str2(str1);
	Mystring str3;

	int r = str1.Find(Mystring("o"));

	cout << r << endl;


	return 0;
}

