#pragma once
#include <iostream>

struct MatrixTerm
{
	int row;
	int col;
	float value = 0.0f;
};

class SparseMatrix
{
public:
	SparseMatrix(int num_row, int num_col, int capacity);
	SparseMatrix(const SparseMatrix& b);
	~SparseMatrix();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	SparseMatrix Transpose() const;


	void PrintTerms() const;
	void Print() const;

private:
	MatrixTerm* terms = nullptr;
	int num_rows = 0;
	int num_cols = 0;
	int capacity = 0;
	int num_terms = 0;
};