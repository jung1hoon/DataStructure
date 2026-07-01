#pragma once

#include <iostream>

void ArrPrint(int arr[], int size);
int InterpolationSearch(int arr[], int low, int high, int x);
int InterpolationSearch2(int arr[], int size, int x);
int SequentialSearch(int arr[], int start, int stop, int x);

int IndexSearch(int arr[], int size, int m, int x);
int IndexSearch2(int arr[], int size, int m, int x);

class IndexTable
{

	struct Index_key
	{
		int key = 0;
		int index = 0;
	};

	Index_key* ptr = nullptr;

public:
	IndexTable(int arr[], int size, int m);
	~IndexTable();

	friend int IndexSearch(int arr[], int size, int m, int x);
	friend int IndexSearch2(int arr[], int size, int m, int x);
};

