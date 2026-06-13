#pragma once
#include <iostream>

struct Node
{
	int item = 0;

	Node* next = nullptr;

	friend std::ostream& operator << (std::ostream& out, const Node& node)
	{
		out << node.item << " ";
		return out;
	}
};



void SetItem(Node* ptr, int value);
void Recurprint(Node* ptr);
void Iterprint(Node* ptr);
void delete_(Node* ptr);
