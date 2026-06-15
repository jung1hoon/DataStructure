#pragma once
#include <cassert>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item;
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{

	}

	SinglyLinkedList(const T& value)
	{
		first = new Node;
		first->item = value;
		size++;
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		first = new Node;
		size = list.size;
		first->item = list.first->item;

		Node* cur = first;
		Node* cur_list = list.first;

		while (cur_list->next != nullptr)
		{
			cur->next = new Node;
			cur->next->item = cur_list->next->item;
			cur = cur->next;
			cur_list = cur_list->next;
		}

	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear()
	{
		Node* cur = first;

		while (cur != nullptr)
		{
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}

		first = nullptr;
		size = 0;
	}

	bool IsEmpty()
	{
		return first == nullptr;
	}

	void pushfront(const T& value)
	{
		Node* temp = first;

		first = new Node;

		first->item = value;

		first->next = temp;

		size++;
	}

	void pushback(const T& value)
	{
		if (!IsEmpty())
		{
			Node* cur = first;

			while (cur->next != nullptr)
			{
				cur = cur->next;
			}

			cur->next = new Node;

			cur->next->item = value;

			size++;
		}
		else
		{
			pushfront(value);
		}
	}

	void popfront()
	{
		if (!IsEmpty())
		{
			Node* temp = first;

			first = first->next;
			size--;

			delete temp;
		}
		else
		{
			std::cout << "Empty" << std::endl;
		}
	}

	T Get(int index)
	{	
		assert(index >= 0);
		assert(index <= size - 1);

		Node* cur = first;

		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}

		return cur->item;

	}

	void Insert(int index, const T& value)
	{
		assert(!IsEmpty());
		assert(index >= 0);
		assert(index <= size - 1);

		if (index >= 1)
		{
			Node* cur = first;

			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}

			Node* temp = cur->next;

			cur->next = new Node;
			cur->next->item = value;
			cur->next->next = temp;

			size++;
		}
		else if (index == 0)
		{
			this->pushfront(value);
		}
		else
		{
			std::cout << "Can't" << std::endl;
		}
	}

	void Erase(int index)
	{
		assert(!IsEmpty());
		assert(index >= 0);
		assert(index <= size - 1);

		if (index >= 1)
		{
			Node* cur = first;

			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}

			Node* temp = cur->next;

			cur->next = temp->next;

			delete temp;

			size--;
		}
		else if (index == 0)
		{
			this->popfront();
		}
		else
		{
			std::cout << "Null" << std::endl;
		}


	}

	void Remove(T value)
	{
		assert(!IsEmpty());

		Node* cur = first;

		if (cur->item == value)
		{
			this->popfront();
		}
		else
		{
			while (cur != nullptr && cur->next != nullptr)
			{
				if (cur->next->item == value)
				{
					Node* temp = cur->next;

					cur->next = temp->next;
					delete temp;
					size--;
				}
				else
				{
					cur = cur->next;
				}
			}
		}
	}

	void Reverse()
	{
		assert(!IsEmpty());

		if (first != nullptr && first->next == nullptr)
		{
			return;
		}

		Node* cur = first;
		Node* pre = nullptr;

		while (cur != nullptr)
		{
			Node* temp = cur->next;

			cur->next = pre;
			pre = cur;
			cur = temp;
		}

		first = pre;
	}

	void Print()
	{
		if (!IsEmpty())
		{
			Node* cur = first;

			while (cur != nullptr && cur->next != nullptr)
			{
				std::cout << cur->item << " " << "->" << " ";
				cur = cur->next;
			}

			if (cur != nullptr)
			{
				std::cout << cur->item << std::endl;
			}
		}
		else
		{
			std::cout << "Empty" << std::endl;
		}
	}


private:

	Node* first = nullptr;
	int size = 0;

};