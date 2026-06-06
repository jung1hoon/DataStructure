#pragma once
#include <iostream>

class Array2D
{
	float** ptr = nullptr;
	int num_rows = 0;
	int num_cols = 0;

public:
	Array2D(int num_rows, int num_cols);

	Array2D(const Array2D& arr);

	~Array2D();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	Array2D Add(const Array2D& arr) const;

	Array2D Transpose() const;

	void print() const;
};