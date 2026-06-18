#pragma once
#include <iostream>
#include <cassert>
#include "stack.h"
#include "queue.h"


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
		std::cout << "del" << std::endl;
	}

private:

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

	void preorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		std::cout << node->item << " ";

		if (node->left != nullptr)
		{
			preorder(node->left);
		}

		if (node->right != nullptr)
		{
			preorder(node->right);
		}
	}

	void Inorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Inorder(node->left);
		std::cout << node->item << " ";
		Inorder(node->right);
	}

	void Postorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Postorder(node->left);
		Postorder(node->right);
		std::cout << node->item << " ";
	}

	void Levelorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Queue<Node*> q;

		q.Enqueue(node);
		Visit(node);

		while (!q.IsEmpty())
		{
			if (q.Front()->left != nullptr)
			{
				q.Enqueue(q.Front()->left);
				Visit(q.Front()->left);
			}

			if (q.Front()->right != nullptr)
			{
				q.Enqueue(q.Front()->right);
				Visit(q.Front()->right);
			}

			q.Dequeue();
		}
	}

	void IterPreorder(Node* node) 
	{
		if (node == nullptr)
		{
			return;
		}
		
		Stack<Node*> s;
		s.push(node);

		while (!s.IsEmpty())
		{
			Node* cur = s.Top();
			s.pop();
			Visit(cur);

			if (cur->right != nullptr)
			{
				s.push(cur->right);
			}

			if (cur->left != nullptr)
			{
				s.push(cur->left);
			}
		}
	}

	void IterInorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Stack<Node*> s;
		Node* cur = node;

		while (cur != nullptr || !s.IsEmpty())
		{
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left;
			}

			cur = s.Top();
			this->Visit(cur);
			s.pop();

			cur = cur->right;
		}
	}

	void IterPostorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		Stack<Node*> s1,s2;
		s1.push(node);

		while (!s1.IsEmpty())
		{
			Node* cur = s1.Top();
			s1.pop();

			s2.push(cur);

			if (cur->left != nullptr)
			{
				s1.push(cur->left);
			}

			if (cur->right != nullptr)
			{
				s1.push(cur->right);
			}
		}

		while (!s2.IsEmpty())
		{
			Node* cur = s2.Top();
			s2.pop();
			Visit(cur);
		}
	}

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

public:

	void Visit(Node* node)
	{
		std::cout << node->item << " ";
	}

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

	void preorder()
	{
		preorder(root);
	}

	void Inorder()
	{
		Inorder(root);
	}

	void Postorder()
	{
		Postorder(root);
	}

	void Levelorder()
	{
		Levelorder(root);
	}

	void IterPreorder()
	{
		IterPreorder(root);
	}

	void IterInorder()
	{
		IterInorder(root);
	}

	void IterPostorder()
	{
		IterPostorder(root);
	}

	void Clear()
	{
		Clear(root);

		root = nullptr;
		size = 0;
	}


protected:
	Node* root = nullptr;
	int size = 0;
};
