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

protected:

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

	void RecurInsert(Node* node, const T1& key_, const T2& value_)
	{
		if (root == nullptr)
		{
			Node* New_Node = new Node;
			New_Node->item.key = key_;
			New_Node->item.value = value_;
			New_Node->left = nullptr;
			New_Node->right = nullptr;

			root = New_Node;
			size++;
			return;
		}

		if (node->item.key == key_)
		{
			node->item.value = value_;
			return;
		}
		else if (node->item.key < key_)
		{
			if (node->right == nullptr)
			{
				Node* New_Node = new Node;
				New_Node->item.key = key_;
				New_Node->item.value = value_;
				New_Node->left = nullptr;
				New_Node->right = nullptr;

				node->right = New_Node;
				size++;
				return;
			}
			else
			{
				RecurInsert(node->right, key_, value_);
			}
		}
		else
		{
			if (node->left == nullptr)
			{
				Node* New_Node = new Node;
				New_Node->item.key = key_;
				New_Node->item.value = value_;
				New_Node->left = nullptr;
				New_Node->right = nullptr;

				node->left = New_Node;
				size++;
				return;
			}
			else
			{
				RecurInsert(node->left, key_, value_);
			}
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

	void Insert1(const T1& key_, const T2& value_)
	{
		Node* cur = root;
		Node* parent = nullptr;
		Node* New_Node = new Node;

		New_Node->item.key = key_;
		New_Node->item.value = value_;
		New_Node->left = nullptr;
		New_Node->right = nullptr;

		if (root == nullptr)
		{
			root = New_Node;
			size++;
			return;
		}

		while (cur != nullptr)
		{
			if (cur->item.key == New_Node->item.key)
			{
				cur->item.value = value_;
				delete New_Node;
				return;
			}
			else if (cur->item.key < New_Node->item.key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				parent = cur;
				cur = cur->left;
			}			
		}

		if (parent->item.key < New_Node->item.key)
		{
			parent->right = New_Node;
		}
		else
		{
			parent->left = New_Node;
		}

		size++;
	}

	void Insert2(const T1& key_, const T2& value_)
	{
		Node* cur = root;
		Node* parent = nullptr;

		while (cur != nullptr)
		{
			parent = cur;

			if (key_ == cur->item.key)
			{
				cur->item.value = value_;
				return;
			}
			else if (key_ < cur->item.key)
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}

		Node* newNode = new Node;

		newNode->item.key = key_;
		newNode->item.value = value_;
		newNode->left = nullptr;
		newNode->right = nullptr;

		if (parent == nullptr)
		{
			root = newNode;
		}
		else if (key_ < parent->item.key)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}

		size++;
	}

	void RecurInsert(const T1& key_, const T2& value_)
	{
		RecurInsert(root, key_, value_);
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



template<typename T1, typename T2>
class AVL : public BinarySearchTree<T1, T2>
{
public:
	using Base = BinarySearchTree<T1, T2>;
	using Node = BinarySearchTree<T1, T2>::Node;
	using Item = BinarySearchTree<T1, T2>::Item;

	AVL(Node* node) : BinarySearchTree<T1, T2>(node)
	{

	}

	~AVL() {}

	int Balance(Node* node)
	{
		if (node != nullptr)
		{
			return this->Height(node->left) - this->Height(node->right);
		}
		else
		{
			return 0;
		}
	}
	
	void RotateLeft(Node*& node)
	{
		if (node == nullptr || node->right == nullptr)
		{
			return;
		}

		Node* newRoot = node->right;
		Node* temp = newRoot->left;

		newRoot->left = node;
		node->right = temp;

		node = newRoot;
	}

	void RotateRight(Node*& node)
	{
		if (node ==  nullptr || node->left == nullptr)
		{
			return;
		}

		Node* newRoot = node->left;
		Node* temp = newRoot->right;

		newRoot->right = node;
		node->left = temp;

		node = newRoot;
	}

private:

	void Insert(Node*& node, const T1& key_, const T2& value_)
	{
		// 1. 빈 자리에 도착하면 새 노드 생성
		if (node == nullptr)
		{
			Node* newNode = new Node;

			newNode->item.key = key_;
			newNode->item.value = value_;
			newNode->left = nullptr;
			newNode->right = nullptr;

			node = newNode;
			this->size++;
			return;
		}

		// 2. BST 규칙대로 삽입
		if (key_ < node->item.key)
		{
			Insert(node->left, key_, value_);
		}
		else if (key_ > node->item.key)
		{
			Insert(node->right, key_, value_);
		}
		else
		{
			// key가 이미 있으면 value만 갱신
			node->item.value = value_;
			return;
		}

		// 3. 삽입 후 현재 노드 기준으로 균형 검사
		int balance = Balance(node);

		// LL case
		if (balance > 1 && Balance(node->left) >= 0)
		{
			RotateRight(node);
			return;
		}

		// RR case
		if (balance < -1 && Balance(node->right) <= 0)
		{
			RotateLeft(node);
			return;
		}

		// LR case
		if (balance > 1 && Balance(node->left) < 0)
		{
			RotateLeft(node->left);
			RotateRight(node);
			return;
		}

		// RL case
		if (balance < -1 && Balance(node->right) > 0)
		{
			RotateRight(node->right);
			RotateLeft(node);
			return;
		}
	}

public:

	void Insert(const T1& key_, const T2& value_)
	{
		Insert(this->root, key_, value_);
	}



};