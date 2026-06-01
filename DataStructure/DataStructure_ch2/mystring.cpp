#include "mystring.h"


Mystring::Mystring() {};

Mystring::Mystring(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		size++;
	}

	ptr = new char[size];

	for (int i = 0; i < size; i++)
	{
		ptr[i] = str[i];
	}
}

Mystring::Mystring(const Mystring& str)
{
	size = str.size;
	ptr = new char[size];

	for (int i = 0; i < size; i++)
	{
		ptr[i] = str.ptr[i];
	}
}

Mystring::~Mystring()
{
	//std::cout << "delete ptr" << std::endl;
	if (ptr != nullptr)
	{
		delete[] ptr;
		ptr = nullptr;
		size = 0;
	}
}

// abdfjdas <-> fjd
int Mystring::Find(const Mystring& str)
{
	int j = 0;
	bool flag = false;

	for (int i = 0; i < size; i++)
	{
		j = 0;

		if (ptr[i] == str.ptr[j])
		{
			for (j = 0; j < str.size; j++)
			{
				if (i + j < size && ptr[i + j] == str.ptr[j])
				{
					flag = true;
				}
				else if (i + j < size && ptr[i + j] != str.ptr[j])
				{
					flag = false;
				}
				else if (i + j >= size)
				{
					flag = false;
				}

				if (flag == false)
				{
					break;
				}
			}

			if (flag == true)
			{
				return i;
			}
		}
	}
	return -1;
}

void Mystring::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ptr[i];
	}
	std::cout << std::endl;
}

bool Mystring::IsEqual(const Mystring& str)
{
	if (size != str.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != str.ptr[i])
			{
				return false;
			}
		}
		return true;
	}
}

int Mystring::length()
{
	return size;
}

bool Mystring::IsEmpty()
{
	if (size == 0 || ptr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mystring::Resize(int new_size)
{
	if (size == new_size)
	{
		return;
	}
	else if (size > new_size)
	{
		char* temp = ptr;
		ptr = new char[new_size];
		for (int i = 0; i < new_size; i++)
		{
			ptr[i] = temp[i];
		}
		size = new_size;
		delete[] temp;
	}
	else
	{
		char* temp = ptr;
		ptr = new char[new_size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = temp[i];
		}
		size = new_size;
		delete[] temp;
	}
}

Mystring Mystring::Substr(int start, int num)
{
	Mystring s;
	s.size = num;
	s.ptr = new char[num];

	for (int i = 0; i < num; i++)
	{
		s[i] = ptr[i + start];
	}
	return s;
}

Mystring& Mystring::Concat(const Mystring& str) 
{
	int origin = size;
	this->Resize(size + str.size);

	for (int i = 0; i < str.size; i++)
	{
		ptr[origin + i] = str.ptr[i];
	}

	return *this;
}

//  1 2 3 (7 8 9) 4 5 6 <---> 1 2 3 4 5 6 0 0 0
Mystring& Mystring::Insert(const Mystring& str, int start)
{
	Mystring temp = str; // 자기 자신을 파라미터에 넣는경우 꼬일수 있기 때문에 임시 객체 생성
	int origin = size;
	this->Resize(size + temp.size);

	for (int i = 0; i < temp.size; i++)
	{
		for (int j = 0; j < origin - start - 1; j++)
		{
			ptr[origin - j + i] = ptr[origin - 1 - j + i];
		}
		//for (int t = origin-1; t >= start; t--)
		//{
		//	ptr[temp.size + t] = ptr[t];
		//}
		ptr[start + i] = temp.ptr[i];
	}
	return *this;
}

Mystring::operator char* ()
{
	return ptr;
}

Mystring& Mystring::operator = (const Mystring& str)
{
	if (this == &str)
	{
		return *this;
	}

	if (ptr != nullptr)
	{
		delete[] ptr;
	}

	size = str.size;
	ptr = new char[size];

	for (int i = 0; i < size; i++)
	{
		ptr[i] = str.ptr[i];
	}

	return *this;
}

std::ostream& operator <<(std::ostream& out, const Mystring& str)
{
	for (int i = 0; i < str.size; i++)
	{
		out << str.ptr[i];
	}
	return out;
}




