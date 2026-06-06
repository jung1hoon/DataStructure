#include "Recur_func.h"
#include "mystring.h"
#include "Polynomial.h"
//#include <vector>
#include "vector.h"


using namespace std;


int main()
{
	Myvector<int> vec1;

	vec1.push_back(0);
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);

	Myvector<int> vec2(vec1);
	Myvector<int> vec3;

	vec3 = vec2;

	vec1.reserve(30);


	cout << "Vec1's size: " << vec1.size() << endl;
	cout << "Vec1's capacity: " << vec1.capacity() << endl;

	cout << endl;

	cout << "Vec2's size: " << vec2.size() << endl;
	cout << "Vec2's capacity: " << vec2.capacity() << endl;

	cout << endl;

	cout << "Vec3's size: " << vec3.size() << endl;
	cout << "Vec3's capacity: " << vec3.capacity() << endl;

	cout << endl;

	vec1.print();
	vec2.print();
	vec3.print();

	vec1[0] = 100;

	cout << vec1[0] << endl;

	return 0;
}

