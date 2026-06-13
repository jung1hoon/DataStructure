#include "Node.h"

void SetItem(Node* ptr, int value) 
{
	ptr->item = value;
}

void Recurprint(Node* ptr)
{
	if (ptr != nullptr)
	{
		Node* cur = ptr;

		std::cout << cur->item << std::endl;

		Recurprint(cur->next);
	}
}

void Iterprint(Node * ptr)
{
	Node* cur = ptr;

	while (cur != nullptr)	
	{
		std::cout << cur->item << std::endl;

		cur = cur->next;
	}
}

void delete_(Node* ptr)
{
	Node* cur = ptr;

	while (cur != nullptr)
	{	
		Node* temp = cur;
		std::cout << "Delete" << std::endl;
		cur = cur->next;
		delete temp;
	}
}