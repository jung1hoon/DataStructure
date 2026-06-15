#pragma once
#include <iostream>
#include <cassert>

template<typename T>
class BinaryTree
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;
	};

	BinaryTree(Node* n)
	{
		root = n;
	}
	
	~BinaryTree()
	{
		Clear();
	}

private:

	int Height(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		return 1 + (Height(node->left) > Height(node->right) ? Height(node->left) : Height(node->right));
	}

	int Sum(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		return node->item + Sum(node->left) + Sum(node->right);
	}


	int Count(Node* node)
	{
		if (node == nullptr)
		{	
			return 0;
		}

		return 1 + Count(node->left) + Count(node->right);
	}

public:

	int Height()
	{
		return Height(root);
	}

	int Sum()
	{
		return Sum(root);
	}

	int Count()
	{
		return Count(root);
	}

	void Clear()
	{
		

	}


protected:
	Node* root = nullptr;
	int size = 0;
};
