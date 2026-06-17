#pragma once

#include <iostream>
#include <cassert>
#include <iomanip>

template<typename T>
class MaxHeap
{
	T* heap = nullptr;
	int capacity = 0;
	int size = 0;

public:
	MaxHeap(int cap = 10)
	{
		capacity = cap;
		heap = new T[capacity + 1];
	}

	~MaxHeap()
	{
		delete[] heap;
	}

	void Resize(int New_cap)
	{
		if (capacity < New_cap)
		{
			T* New_heap = new T[New_cap + 1];

			for (int i = 1; i <= capacity; i++)
			{
				New_heap[i] = heap[i];
			}

			delete[] heap;
			heap = New_heap;
			capacity = New_cap;
		}
		else
		{
			return;
		}
	}

	T Top()
	{
		return heap[1];
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void Push(const T& value)
	{
		if (size >= capacity)
		{
			Resize(capacity * 2);
		}

		size++;
		int cur = size;

		while (cur != 1 && value > heap[cur / 2])
		{
			heap[cur] = heap[cur / 2];
			cur = cur / 2;
		}

		heap[cur] = value;
		
	}

	void Pop()
	{
		if (!IsEmpty())
		{
			if (size == 1)
			{
				size--;
				return;
			}

			T last = heap[size];
			size--;

			int cur = 1;
			int compareLR = 0;

			while (cur <= size)
			{
				if (cur * 2 <= size && cur * 2 + 1 <= size)
				{
					compareLR = heap[cur * 2] > heap[cur * 2 + 1] ? cur * 2 : cur * 2 + 1;
				}
				else if (cur * 2 <= size && cur * 2 + 1 > size)
				{
					compareLR = cur * 2;
				}
				else if (cur * 2 > size && cur * 2 + 1 > size)
				{
					break;
				}


				if (last < heap[compareLR])
				{
					heap[cur] = heap[compareLR];
					cur = compareLR;
				}
				else
				{
					break;
				}
			}

			heap[cur] = last;
		}
	}

	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			std::cout << " " << heap[i];
		}
		std::cout << std::endl;
	}
};



template<typename T>
class MinHeap
{
	T* heap = nullptr;
	int capacity = 0;
	int size = 0;

public:
	MinHeap(int cap = 10)
	{
		capacity = cap;
		heap = new T[capacity + 1];
	}

	~MinHeap()
	{
		delete[] heap;
	}

	void Resize(int New_cap)
	{
		if (capacity < New_cap)
		{
			T* New_heap = new T[New_cap + 1];

			for (int i = 1; i <= capacity; i++)
			{
				New_heap[i] = heap[i];
			}

			delete[] heap;
			heap = New_heap;
			capacity = New_cap;
		}
		else
		{
			return;
		}
	}

	T Top()
	{
		return heap[1];
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void Push(const T& value)
	{
		if (size >= capacity)
		{
			Resize(capacity * 2);
		}

		size++;
		int cur = size;

		while (cur != 1 && value < heap[cur / 2])
		{
			heap[cur] = heap[cur / 2];
			cur = cur / 2;
		}

		heap[cur] = value;

	}

	void Pop()
	{
		if (!IsEmpty())
		{
			if (size == 1)
			{
				size--;
				return;
			}

			T last = heap[size];
			size--;

			int cur = 1;
			int compareLR = 0;

			while (cur <= size)
			{
				if (cur * 2 <= size && cur * 2 + 1 <= size)
				{
					compareLR = heap[cur * 2] < heap[cur * 2 + 1] ? cur * 2 : cur * 2 + 1;
				}
				else if (cur * 2 <= size && cur * 2 + 1 > size)
				{
					compareLR = cur * 2;
				}
				else if (cur * 2 > size && cur * 2 + 1 > size)
				{
					break;
				}


				if (last > heap[compareLR])
				{
					heap[cur] = heap[compareLR];
					cur = compareLR;
				}
				else
				{
					break;
				}
			}

			heap[cur] = last;
		}
	}

	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			std::cout << " " << heap[i];
		}
		std::cout << std::endl;
	}
};
