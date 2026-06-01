#pragma once

#include <iostream>

class Mystring
{
public:
	Mystring() {}
	Mystring(const char* str)
	{
		for (int i = 0; str[i] !='\0'; i++)
		{
			size++;
		}
		ptr = new char[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = str[i];
		}
	}
	Mystring(const Mystring& str)
	{
		size = str.size;
		ptr = new char[size];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = str.ptr[i];
		}
	}
	
	~Mystring()
	{
		std::cout << "delete ptr" << std::endl;
		delete[] ptr;
	}

	int Find(const Mystring& str)
	{
		bool flag = false;
		int i, j;

		for (i = 0; i < str.size;)
		{
			for (j = 0; j < size; j++)
			{
				if (ptr[j] == str.ptr[i])
				{
					flag = true;
					i++;
			
				}
				else
				{
					flag = false;
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << ptr[i];
		}
		std::cout << std::endl;
	}

	bool IsEqual(const Mystring& str)
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
				else
				{
					return true;
				}
			}
		}
	}

	int length()
	{
		return size;
	}

	bool IsEmpty()
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

	void Resize(int new_size)
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

	Mystring Substr(int start, int num)
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

	Mystring& Concat(const Mystring& str)
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
	Mystring& Insert(const Mystring& str, int start)
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

		operator char*()
	{
			return ptr;
	}

	Mystring& operator = (const Mystring& str)
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

	friend std::ostream& operator <<(std::ostream& out, const Mystring& str)
	{
		for (int i = 0; i < str.size; i++)
		{
			out << str.ptr[i];
		}
		return out;
	}

private:
	char* ptr = nullptr;
	int size = 0;
};

