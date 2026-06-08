#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int num_row, int num_col, int capacity_)
{
	num_rows = num_row;
	num_cols = num_col;
	capacity = capacity_;
	terms = new MatrixTerm[capacity];

	for (int i = 0; i < capacity; i++)
	{
		terms[i].row = num_rows * num_cols;
		terms[i].col = num_rows * num_cols;
	}
}

SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	num_rows = b.num_rows;
	num_cols = b.num_cols;
	num_terms = b.num_terms;
	capacity = b.capacity;

	terms = new MatrixTerm[capacity];

	for (int i = 0; i < capacity; i++)
	{
		terms[i].row = b.terms[i].row;
		terms[i].col = b.terms[i].col;
		terms[i].value = b.terms[i].value;
	}
}

SparseMatrix::~SparseMatrix()
{
	if (terms != nullptr)
	{
		delete[] terms;
		terms = nullptr;
	}
}

void SparseMatrix::SetValue(int row, int col, float value)
{	
	if (value == 0.0f)
	{
		return;
	}

	
	//// 정렬 x
	//if (num_terms < capacity)
	//{
	//	terms[num_terms].row = row;
	//	terms[num_terms].col = col;
	//	terms[num_terms].value = value;
	//	num_terms++;
	//}
	//else
	//{
	//	std::cout << "Can't" << std::endl;
	//	return;
	//}


	// 정렬 O
	if (num_terms >= capacity)
	{
		std::cout << "Can't" << std::endl;
		return;
	}

	int index = 0;

	for (int i = 0; i < num_terms; i++)
	{
		if (terms[i].row < row)
		{
			index++;
		}
		else if (terms[i].row == row && terms[i].col < col)
		{
			index++;
		}
		else if (terms[i].row == row && terms[i].col == col)
		{
			terms[i].value = value;
			return;
		}
	}

	for (int i = num_terms; i > index; i--)
	{
		terms[i] = terms[i - 1];
	}
	
	terms[index].row = row;
	terms[index].col = col;
	terms[index].value = value;
	num_terms++;

	// 0,2
	// 0,3     <- 1,0
	// 1,1
}

float SparseMatrix::GetValue(int row, int col) const
{
	for (int i = 0; i < num_terms; i++)
	{
		if (terms[i].row == row && terms[i].col == col)
		{
			return terms[i].value;
		}
	}
	
	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose() const
{
	SparseMatrix temp(num_cols, num_rows, capacity);

	for (int i = 0; i < num_terms; i++)
	{
		temp.SetValue(terms[i].col, terms[i].row, this->GetValue(terms[i].row, terms[i].col));
	}
	
	return temp;
}

void SparseMatrix::PrintTerms() const
{
	for (int i = 0; i < num_terms; i++)
	{
		std::cout << "[" << terms[i].row << ", ";
		std::cout << terms[i].col << ", ";
		std::cout << terms[i].value << "]" << std::endl;
	}
}

void SparseMatrix::Print() const
{
	int i = 0;

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			if (num_cols * r + c == terms[i].row * num_cols + terms[i].col)
			{
				std::cout << terms[i].value << " ";
				i++;
			}
			else
			{
				std::cout << "0" << " ";
			}
		}
		std::cout << std::endl;
	}
}
