#pragma once

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