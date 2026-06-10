#pragma once


#include <iostream>
#include <cassert>
#include <iomanip>

//1. 선입선출 "한칸씩" 추가하고 삭제.
//2. front -> 첫번째의 앞 인덱스. rear 마지막 원소 인덱스
//3. front == rear => 빈 Queue
//4. front인덱스 자리는 빈칸 취급 => capacity - 1 이 최대 size.
//5. 원형 Queue이므로 n % capacity 로 연산 -> 인덱스 => (0 ~ capacity - 1) => capacity로 나눴을 때 나머지
//6. size가 capacity - 1 인 최대 사이즈에서 기존 원소 삭제 없이 추가하려면 capacity를 추가


template<typename T>
class Queue
{
protected:
	T* ptr = nullptr;
	int front = 0;
	int rear = 0;
	int capacity = 2;
	bool print_debug = false;

public:
	Queue(int capacity_ = 2)
	{
		assert(capacity_ > 0);

		capacity = capacity_;
		ptr = new T[capacity];
	}
	Queue(const Queue& q)
	{
		capacity = q.capacity;
		front = q.front;
		rear = q.rear;

		ptr = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			ptr[i] = q.ptr[i];
		}
	}
	~Queue()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
			ptr = nullptr;
		}
	}

	bool IsEmpty()
	{
		return front == rear;
	}

	bool IsFull()
	{
		return (rear + 1) % capacity == front;
	}

	int Size()
	{
		if (front <= rear)
		{
			return rear - front;
		}
		else
		{
			int s1 = (capacity - 1) - front;
			int s2 = rear + 1;

			return s1 + s2;
		}
	}

	int& _capacity()
	{
		return capacity;
	}

	T& Front()
	{
		assert(!IsEmpty());

		return ptr[(front + 1) % capacity];
	}

	int& _front()
	{
		return front;
	}


	T& Rear()
	{
		assert(!IsEmpty());

		return ptr[rear];
	}

	int& _rear()
	{
		return rear;
	}

	void Resize()
	{
		int new_capacity = capacity * 2;
		int size = Size();

		T* temp = ptr;

		ptr = new T[new_capacity];


		int start = (front + 1) % capacity;

		//for (int i = 1; i <= size; i++)
		//{
		//	ptr[i] = temp[(front + i) % capacity];
		//}

		//front = 0;
		//rear = size;

		if (front <= rear)
		{
			// - - 2 4 5 6 -> - 2 4 5 6 - - - - - - ...
			memcpy(ptr + 1, temp + start, sizeof(T) * (size));
			front = 0;
			rear = size;
		}
		else
		{
			int count = (capacity - 1) - front;
			// 1 2 3 4 - 5 6 7 -> - 5 6 7 1 2 3 4 - - - - - ...
			memcpy(ptr + 1, temp + start, sizeof(T) * count);
			memcpy(ptr + count + 1, temp, sizeof(T) * (rear + 1));
			front = 0;
			rear = size;

		}

		capacity = new_capacity;

		delete[] temp;
	}

	void Enqueue(const T& value)
	{
		if (this->Size() < capacity - 1 )
		{
			rear = (rear + 1) % capacity;
			ptr[rear] = value;
		}
		else
		{
			this->Resize();

			rear = (rear + 1) % capacity;
			ptr[rear] = value;

		}
	}

	void Dequeue()
	{
		assert(!IsEmpty());
		front = (front + 1) % capacity;
	}

	void Print()
	{	
		int start = (front + 1) % capacity;

		for (int i = start; i != (rear + 1) % capacity; i = (i + 1) % capacity)
		{
			std::cout << ptr[i] << " ";
		}
		std::cout << std::endl;
	}

};


