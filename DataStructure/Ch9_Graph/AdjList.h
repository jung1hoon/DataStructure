#pragma once
#include "../shared/queue.h"
#include <iostream>


template<typename T>
class AdjList
{
public:

	struct Vertex
	{
		T item = T();
	};

	struct Node
	{
		int vertex = -1; // vertex_Index
		Node* next = nullptr;
	};

	AdjList(int capa)
	{
		capacity = capa;

		vertices = new Vertex[capacity];
		list = new Node * [capacity];
		for (int i = 0; i < capacity; i++)
		{
			list[i] = nullptr;
		}

		visited = new bool[capacity];

		for (int i = 0; i < capacity; i++)
		{
			visited[i] = false;
		}

		n = 0;
	}

	~AdjList()
	{
		delete[] vertices;

		if (list != nullptr)
		{
			for (int i = 0; i < capacity; i++)
			{
				Node* cur = list[i];

				while (cur != nullptr)
				{
					Node* temp = cur;
					cur = cur->next;
					delete temp;
				}
			}

			delete[] list;
		}

		delete[] visited;
	}
	void InsertVertex(T item_)
	{
		if (n >= capacity)
		{
			return;
		}

		vertices[n].item = item_;
		n++;
	}

	void InsertEdge(int u, int v)
	{	
		if (u < 0 || u >= n || v < 0 || v >= n)
		{
			return;
		}

		if (list[u] == nullptr)
		{
			list[u] = new Node{ v, nullptr };
		}
		else
		{	
			Node* cur = list[u];

			while (cur->next != nullptr)
			{
				cur = cur->next;
			}

			cur->next = new Node{ v, nullptr };
		}
	}

	void ResetVisited()
	{
		if (visited == nullptr)
		{
			visited = new bool[capacity];
		}

		for (int i = 0; i < capacity; i++)
		{
			visited[i] = false;
		}
	}

	void DFS(int u)
	{
		if (u < 0 || u >= n)
		{
			return;
		}

		if (visited[u] == true)
		{
			return;
		}
		
		std::cout << u << std::endl;

		visited[u] = true;

		Node* cur = list[u];

		while (cur != nullptr)
		{
			int v = cur->vertex;

			if (visited[v] == false)
			{
				DFS(v);
			}

			cur = cur->next;
		}
	}

	void BFS(int u)
	{

		if (u < 0 || u >= n)
		{
			return;
		}

		if (visited[u] == true)
		{
			return;
		}

		Queue<int> q;

		visited[u] = true;
		q.Enqueue(u);

		while (!q.IsEmpty())
		{
			int s = q.Front();
			q.Dequeue();

			std::cout << s << std::endl;

			Node* cur = list[s];

			while (cur != nullptr)
			{
				int v = cur->vertex;

				if (visited[v] == false)
				{
					q.Enqueue(v);
					visited[v] = true;
				}

				cur = cur->next;
			}
		}
	}


private:
	int n = 0;
	int capacity = 0;
	Vertex* vertices = nullptr;
	Node** list = nullptr;

	bool* visited = nullptr;
};