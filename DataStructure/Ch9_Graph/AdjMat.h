#pragma once

#include "../shared/queue.h"
#include <iostream>

template<typename T>
class AdjMat
{
public:

	struct Vertex
	{
		T item = T();
	};

	AdjMat(int capa)
	{
		capacity = capa;

		matrix = new int* [capacity];

		for (int i = 0; i < capacity; i++)
		{
			matrix[i] = new int[capacity];

			for (int j = 0; j < capacity; j++)
			{
				matrix[i][j] = 0;
			}
		}

		vertices = new Vertex[capacity];

		visited = new bool[capacity];

		for (int i = 0; i < capacity; i++)
		{
			visited[i] = false;
		}

		n = 0;
	}

	~AdjMat()
	{	
		if (vertices != nullptr)
		{
			delete[] vertices;
		}

		if (matrix != nullptr)
		{
			for (int i = 0; i < capacity; i++)
			{
				if (matrix[i] != nullptr)
				{
					delete[] matrix[i];
				}
			}

			delete[] matrix;
		}

		if (visited != nullptr)
		{
			delete[] visited;
		}
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
		if (u >= 0 && u < n && v >= 0 && v < n)
		{
			matrix[u][v] = 1;
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

		for (int v = 0; v < n; v++)
		{
			if (matrix[u][v] == 1 && visited[v] == false)
			{
				DFS(v);
			}
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

			for (int v = 0; v < n; v++)
			{
				if (matrix[s][v] == 1 && visited[v] == false)
				{
					visited[v] = true;
					q.Enqueue(v);
				}
			}
		}
	}

private:

	int** matrix = nullptr;
	Vertex* vertices = nullptr;
	int n = 0;
	int capacity = 0;

	bool* visited = nullptr;
};

