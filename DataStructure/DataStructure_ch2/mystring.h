#pragma once

#include <iostream>

class Mystring
{
public:
	Mystring();

	Mystring(const char* str);

	Mystring(const Mystring& str);
	
	~Mystring();

	int Find(const Mystring& str);

	void print();

	bool IsEqual(const Mystring& str);

	int length();

	bool IsEmpty();

	void Resize(int new_size);

	Mystring Substr(int start, int num);

	Mystring& Concat(const Mystring& str);

	Mystring& Insert(const Mystring& str, int start);

	operator char* ();

	Mystring& operator = (const Mystring& str);

	friend std::ostream& operator <<(std::ostream& out, const Mystring& str);

private:
	char* ptr = nullptr;
	int size = 0;
};

