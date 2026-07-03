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

	AdjList()
	{

	}


private:
	int n = 0;
	int capacity = 0;
	Vertex* vertices = nullptr;


	bool* visited = nullptr;
};