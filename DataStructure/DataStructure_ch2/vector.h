#pragma once
#include <iostream>

template<typename T>
class Myvector
{
	T* ptr = nullptr;
	int size_ = 0;
	int capacity_ = 3;

public:
	Myvector()
	{
		ptr = new T[capacity_];

	}

	Myvector(const Myvector& vec)
	{
		size_ = vec.size_;
		capacity_ = vec.capacity_;
		ptr = new T[capacity_];

		for (int i = 0; i < size_; i++)
		{
			ptr[i] = vec.ptr[i];
		}

	}

	~Myvector()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
		}
	}

	void push_back(T t)
	{
		if (size_ < capacity_)
		{
			ptr[size_] = t;
			size_++;
		}
		else if (size_ == capacity_)
		{
			resize(capacity_ * 2);
			ptr[size_] = t;
			size_++;
		}
		else
		{
			return;
		}
	}

	void reserve(int _capacity)
	{
		capacity_ = _capacity;
		T* temp = new T[capacity_];
		
		for (int i = 0; i < size_; i++)
		{
			temp[i] = ptr[i];
		}

		delete[] ptr;
		ptr = temp;
	}

	int size() const
	{
		return size_;
	}

	int capacity() const
	{
		return capacity_;
	}

	void print() const
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << ptr[i] << " ";
		}

		std::cout << std::endl;
	}

	Myvector& operator = (const Myvector& vec)
	{
		if (this == &vec)
		{
			return *this;
		}

		if (ptr != nullptr)
		{
			delete[] ptr;
			ptr = nullptr;
		}

		capacity_ = vec.capacity_;
		size_ = vec.size_;

		ptr = new T[capacity_];

		for (int i = 0; i < size_; i++)
		{
			ptr[i] = vec.ptr[i];
		}

		return *this;
	}
};
