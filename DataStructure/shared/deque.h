#pragma once

#include "queue.h"
#include <iostream>
#include <cassert>
#include <iomanip>

template<typename T>
class Deque : public Queue<T>
{
	
public:

	void push_front(const T& value)
	{
		if (this->IsFull())
		{
			this->Resize();
		}

		this->ptr[this->front] = value;
		this->front = ((this->front - 1) + this->capacity) % this->capacity;
	}

	void push_back(const T& value)
	{
		this->Enqueue(value);
	}

	void pop_front()
	{
		if (!this->IsEmpty())
		{
			this->front = (this->front + 1) % this->capacity;
		}
	}

	void pop_back()
	{
		if (!this->IsEmpty())
		{
			this->rear = ((this->rear - 1) + this->capacity) % this->capacity;
		}
	}
};
