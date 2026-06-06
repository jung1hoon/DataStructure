#include "Array2D.h"

Array2D::Array2D(int num_row, int num_col)
{
	num_rows = num_row;
	num_cols = num_col;

	ptr = new float* [num_rows];

	for (int i = 0; i < num_rows; i++)
	{
		ptr[i] = new float[num_cols];
	}

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			ptr[r][c] = 0.0f;
		}
	}
}

Array2D::Array2D(const Array2D& arr)
{
	num_rows = arr.num_rows;
	num_cols = arr.num_cols;

	ptr = new float* [num_rows];

	for (int i = 0; i < num_rows; i++)
	{
		ptr[i] = new float[num_cols];
	}

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			ptr[r][c] = arr.ptr[r][c];
		}
	}
	
}

Array2D::~Array2D()
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < num_rows; i++)
		{
			if (ptr[i] != nullptr)
			{
				delete[] ptr[i];
				ptr[i] = nullptr;
			}
		}

		delete[] ptr;
	}
}

void Array2D::SetValue(int row, int col, float value)
{
	if (row >= 0 && col >= 0 && row < num_rows && col < num_cols)
	{
		ptr[row][col] = value;
	}
}

float Array2D::GetValue(int row, int col) const
{
	if (row >= 0 && col >= 0 && row < num_rows && col < num_cols)
	{
		return ptr[row][col];
	}
	else
	{
		std::cout << "Not defined index ";
		return -1.0f;
	}
}

Array2D Array2D::Add(const Array2D& arr) const
{
	Array2D temp(num_rows, num_cols);

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			temp.SetValue(r, c, this->GetValue(r, c) + arr.GetValue(r, c));
		}
	}
	return temp;
}

Array2D Array2D::Transpose() const
{
	Array2D temp(num_cols, num_rows);

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			temp.SetValue(c, r, this->GetValue(r, c));
		}
	}

	return temp;
}

void Array2D::print() const
{
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			std::cout << this->GetValue(r, c) << " ";
		}
		std::cout << std::endl;
	}
}
