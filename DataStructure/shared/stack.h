#pragma once

#include <iostream>
#include <cassert>


template<typename T>
class Stack
{
	T* ptr = nullptr;
	int top = -1;
	int capacity = 0;

public:

	Stack(int capacity_ = 1)
	{
		capacity = capacity_;

		ptr = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			ptr[i] = T();
		}
	}

	Stack(const Stack& st)
	{
		top = st.top;
		capacity = st.capacity;

		ptr = new T[capacity];

		for (int i = 0; i <= top ; i++)
		{
			ptr[i] = st.ptr[i];
		}
	}

	~Stack()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
			ptr = nullptr;
		}
	}

	void resize(int cp)
	{
		if (cp == capacity)
		{
			return;
		}

		T* temp = ptr;

		ptr = new T[cp];

		if (cp > capacity)
		{
			for (int i = 0; i < capacity; i++)
			{
				ptr[i] = temp[i];
			}
		}
		else
		{
			for (int i = 0; i < cp; i++)
			{
				ptr[i] = temp[i];
			}

			top = cp - 1;
		}

		capacity = cp;

		delete[] temp;
	}

	T& Top() 
	{	
		assert(top >= 0);

		return ptr[top];
	}

	void push(const T& p)
	{
		if (top < capacity - 1)
		{
			top++;
			ptr[top] = p;
		}
		else
		{
			this->resize(capacity * 2);
			top++;
			ptr[top] = p;
		}
	}

	void pop()
	{
		if (top >= 0)
		{
			top--;
		}
		else
		{
			std::cout << "Not Exist" << std::endl;
		}
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	int Size()
	{
		return top + 1;
	}


	void Print()
	{
		if (top == -1)
		{
			std::cout << "" << std::endl;
			return;
		}

		for (int i = 0; i <= top; i++)
		{
			std::cout << ptr[i] << " ";
		}

		std::cout << std::endl;
	}


};