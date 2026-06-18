#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "stack.h"
#include "queue.h"


template<typename T1, typename T2>
class BinarySearchTree
{
public:

	struct Item
	{
		T1 key =T1();
		T2 value = T2();
	};

	struct Node
	{
		Item item;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	BinarySearchTree(Node* node)
	{
		root = node;
		size = 1;
	}

	~BinarySearchTree()
	{
		Clear();
	}

private:
	Node* root = nullptr;
	int size = 0;

	void Clear(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Clear(node->left);
		Clear(node->right);
		delete node;
	}

	int Height(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int leftHeight = Height(node->left);
		int rightHeight = Height(node->right);

		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

	void PrintSpaces(int count)
	{
		for (int i = 0; i < count; i++)
		{
			std::cout << " ";
		}
	}

	void Inorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Inorder(node->left);
		std::cout << node->item.key << node->item.value << " ";
		Inorder(node->right);
	}

	Item* RecurGet(const T1& key_, Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->item.key == key_)
		{
			return &(node->item);
		}
		else if (node->item.key < key_)
		{
			return RecurGet(key_, node->right);
		}
		else
		{
			return RecurGet(key_, node->left);
		}
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
		Clear(root);
	}

	void Inorder()
	{
		Inorder(root);
	}

	void Insert(const T1& key_, const T2& value_)
	{
		Node* cur = root;
		Node* New_Node = new Node;

		New_Node->item.key = key_;
		New_Node->item.value = value_;

		while (true)
		{
			if (cur->item.key == New_Node->item.key)
			{
				cur->item.value = value_;
				delete New_Node;
				return;
			}
			else if (cur->item.key < New_Node->item.key)
			{
				if (cur->right != nullptr)
				{
					cur = cur->right;
				}
				else
				{
					cur->right = New_Node;
					size++;
					return;
				}
				
			}
			else if(cur->item.key > New_Node->item.key)
			{
				if (cur->left != nullptr)
				{
					cur = cur->left;
				}
				else
				{
					cur->left = New_Node;
					size++;
					return;
				}
			}
			else
			{
				break;
			}
		}
	}

	Item* Get(const T1& key_)
	{
		Node* cur = root;

		while (cur != nullptr)
		{
			if (cur->item.key == key_)
			{
				return &(cur->item);
			}
			else if (cur->item.key < key_)
			{
				cur = cur->right;
			}
			else if (cur->item.key > key_)
			{
				cur = cur->left;
			}
		}
		std::cout << "Nothing" << std::endl;
		return nullptr;
	}

	Item* RecurGet(const T1& key_)
	{
		return RecurGet(key_, root);
	}

	Node* FindNode(const T1& key_)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		Node* cur = root;

		while (cur->item.key != key_)
		{
			if (cur->item.key < key_)
			{
				if (cur->right != nullptr)
				{
					cur = cur->right;
				}
				else
				{
					std::cout << "Nothing" << std::endl;
					return nullptr;
				}
			}
			else if (cur->item.key > key_)
			{
				if (cur->left != nullptr)
				{
					cur = cur->left;
				}
				else
				{
					std::cout << "Nothing" << std::endl;
					return nullptr;
				}
			}
		}
		
		return cur;
	}

	Node* FindParent(const T1& key_)
	{
		Node* parent = nullptr;
		Node* cur = root;

		while (cur != nullptr)
		{
			if (cur->item.key < key_)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->item.key > key_)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return parent;
			}
		}

		return nullptr;
	}


	void Remove(const T1& key_)
	{	
		Node* key_node = FindNode(key_);

		if (key_node == nullptr)
		{
			std::cout << "Nothing" << std::endl;
			return;
		}

		Node* parent = FindParent(key_);

		if (key_node->left == nullptr && key_node->right == nullptr)
		{
			if (key_node == root)
			{
				delete key_node;
				size--;
				root = nullptr;
				return;
			}

			if (parent->left == key_node)
			{
				parent->left = nullptr;
			}
			else if (parent->right == key_node)
			{
				parent->right = nullptr;
			}

			delete key_node;
			size--;
			return;
		}
		else if (key_node->left != nullptr && key_node->right == nullptr)
		{
			if (parent != nullptr)
			{
				parent->left = key_node->left;
			}
			else
			{
				root = key_node->left;
			}
			delete key_node;
			size--;
			return;
		}
		else if (key_node->left == nullptr && key_node->right != nullptr)
		{
			if (parent != nullptr)
			{
				parent->right = key_node->right;
			}
			else
			{
				root = key_node->right;
			}
			delete key_node;
			size--;
			return;
		}
		else if (key_node->left != nullptr && key_node->right != nullptr)
		{
			Node* cur = key_node->right;

			while (cur->left != nullptr)
			{
				cur = cur->left;
			}

			Item _item = cur->item;		

			Remove(cur->item.key);

			key_node->item = _item;
		}
	}

	void Remove2(const T1& key_)
	{
		Node* key_node = FindNode(key_);

		if (key_node == nullptr)
		{
			std::cout << "Nothing" << std::endl;
			return;
		}

		Node* parent = FindParent(key_);

		// Case 1, 2: 자식이 0개 또는 1개
		if (key_node->left == nullptr || key_node->right == nullptr)
		{
			Node* child = nullptr;

			if (key_node->left != nullptr)
			{
				child = key_node->left;
			}
			else
			{
				child = key_node->right;
			}

			if (parent == nullptr)
			{
				root = child;
			}
			else if (parent->left == key_node)
			{
				parent->left = child;
			}
			else if (parent->right == key_node)
			{
				parent->right = child;
			}

			delete key_node;
			size--;
			return;
		}

		// Case 3: 자식이 2개
		Node* succParent = key_node;
		Node* succ = key_node->right;

		while (succ->left != nullptr)
		{
			succParent = succ;
			succ = succ->left;
		}

		key_node->item = succ->item;

		Node* succChild = succ->right;

		if (succParent->left == succ)
		{
			succParent->left = succChild;
		}
		else
		{
			succParent->right = succChild;
		}

		delete succ;
		size--;
	}

	void Print()
	{
		if (root == nullptr)
		{
			std::cout << "Empty Tree" << std::endl;
			return;
		}

		int h = Height(root);

		Queue<Node*> q;
		q.Enqueue(root);

		const int nodeWidth = 3;

		for (int level = 0; level < h; level++)
		{
			int nodeCount = 1 << level;

			int firstSpaces = ((1 << (h - level - 1)) - 1) * nodeWidth;
			int betweenSpaces = ((1 << (h - level)) - 1) * nodeWidth;

			PrintSpaces(firstSpaces);

			for (int i = 0; i < nodeCount; i++)
			{
				Node* cur = q.Front();
				q.Dequeue();

				if (cur != nullptr)
				{
					std::cout << std::setw(nodeWidth) << cur->item.key << cur->item.value;

					q.Enqueue(cur->left);
					q.Enqueue(cur->right);
				}
				else
				{
					std::cout << std::setw(nodeWidth) << " ";

					q.Enqueue(nullptr);
					q.Enqueue(nullptr);
				}

				PrintSpaces(betweenSpaces);
			}

			std::cout << std::endl;
		}
	}
};