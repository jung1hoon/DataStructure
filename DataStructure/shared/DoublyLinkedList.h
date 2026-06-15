#pragma once
#include <cassert>
#include <iostream>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;
	};

	DoublyLinkedList()
	{

	}

	DoublyLinkedList(const DoublyLinkedList& list)
	{
		size = list.size;

		if (!list.IsEmpty())
		{
			first = new Node;
			first->item = list.first->item;
			Node* list_cur = list.first;
			Node* cur = first;

			while (list_cur->right != nullptr)
			{
				cur->right = new Node;
				cur->right->item = list_cur->right->item;
				cur->right->left = cur;
				cur = cur->right;
				list_cur = list_cur->right;
			}
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear()
	{
		Node* cur = first;

		while (cur != nullptr)
		{
			Node* temp = cur;
			cur = cur->right;
			delete temp;
			size--;
		}
		first = nullptr;
	}

	bool IsEmpty() const
	{
		return first == nullptr;
	}

	void pushfront(const T& value)
	{
		Node* temp = first;
		
		first = new Node;
		first->left = nullptr;
		first->right = temp;
		first->item = value;

		if (temp != nullptr)
		{
			temp->left = first;
		}

		size++;
	}

	void pushback(const T& value)
	{
		if (!IsEmpty())
		{
			Node* cur = first;

			while (cur->right != nullptr)
			{
				cur = cur->right;
			}

			cur->right = new Node;
			cur->right->left = cur;
			cur->right->item = value;

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

			first = first->right;

			if (first != nullptr)
			{
				first->left = nullptr;
			}

			delete temp;
			size--;
		}
		else
		{
			std::cout << "Can't, because of Empty List" << std::endl;
		}
	}

	T GetValue(int index)
	{
		assert(index >= 0);
		assert(index <= size - 1);

		Node* cur = first;

		for (int i = 0; i < index; i++)
		{
			cur = cur->right;
		}

		return cur->item;
	}

	void Insert(int index, const T& value)
	{
		if (index < 0 || index > size)
		{
			return;
		}

		if (index == 0)
		{
			pushfront(value);
			return;
		}

		if (index == size)
		{
			pushback(value);
			return;
		}

		Node* cur = first;

		for (int i = 0; i < index; i++)
		{
			cur = cur->right;
		}

		Node* New_Node = new Node;

		New_Node->left = cur->left;
		New_Node->right = cur;
		New_Node->item = value;

		cur->left->right = New_Node;
		cur->left = New_Node;

		size++;

	}

	int Find_index(const T& value)
	{
		assert(!IsEmpty());

		int cur_index = 0;
		Node* cur = first;

		while (cur != nullptr && cur->item != value)
		{
			cur = cur->right;
			cur_index++;
		}

		if (cur == nullptr)
		{
			return -1;
		}
		else
		{
			return cur_index;
		}

	}

	void Erase(int index)
	{
		assert(!IsEmpty());
		assert(index >= 0);
		assert(index <= size - 1);

		if (index == 0)
		{
			popfront();
			return;
		}

		Node* cur = first;

		for (int i = 0; i < index; i++)
		{
			cur = cur->right;
		}

		if (cur->left != nullptr)
		{
			cur->left->right = cur->right;
		}

		if (cur->right != nullptr)
		{
			cur->right->left = cur->left;
		}

		delete cur;
		size--;
	}

	void Remove(const T& value)
	{
		assert(!IsEmpty());

		if (first->item == value)
		{
			popfront();
			return;
		}

		Node* cur = first->right;

		while (cur != nullptr && cur->item != value)
		{
			cur = cur->right;
		}

		if (cur == nullptr)
		{
			std::cout << "Nothing" << std::endl;
			return;
		}

		if (cur->left != nullptr)
		{
			cur->left->right = cur->right;
		}

		if (cur->right != nullptr)
		{
			cur->right->left = cur->left;
		}

		delete cur;
		size--;
	}

	void Reverse()
	{
		assert(!IsEmpty());

		if (first != nullptr && first->right == nullptr)
		{
			return;
		}

		Node* cur = first;
		Node* temp = nullptr;

		while (cur != nullptr)
		{
			temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;

			cur = cur->left;
		}

		first = temp->left;
	}

	void Print()
	{
		if (IsEmpty())
		{
			std::cout << "Empty" << std::endl;
		}
		else
		{	
			Node* cur = first;

			std::cout << "Forward : ";

			while (cur != nullptr)
			{
				std::cout << cur->item << " ";
				cur = cur->right;
			}

			std::cout << std::endl;

			std::cout << "Backward : ";

			cur = first;

			for (int i = 0; i < size - 1; i++)
			{
				cur = cur->right;
			}

			while (cur != nullptr)
			{
				std::cout << cur->item << " ";
				cur = cur->left;
			}

			std::cout << std::endl;
		}
	}

private:

	Node* first = nullptr;
	int size = 0;

};