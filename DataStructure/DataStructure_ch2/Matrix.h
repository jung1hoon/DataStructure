#pragma once
#include <iostream>
#include <cassert>

template<typename T>
class Matrix
{
	T* ptr = nullptr;
	int num_row = 0;
	int num_col = 0;

public:
	Matrix(int num_rows, int num_cols)
	{
		num_row = num_rows;
		num_col = num_cols;
		int size = num_rows * num_cols;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = T{}; // T{} 는 타입에 맞는 기본값 만들어줌
						  //ex) int{} -> 0, float{} -> 0.0f, std::string{} -> "", ...
		}
	}

	Matrix(const Matrix& mx)
	{
		num_row = mx.num_row;
		num_col = mx.num_col;

		int size = num_row * num_col;

		ptr = new T[size];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = mx.ptr[i];
		}
	}

	~Matrix()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
			ptr = nullptr;
		}
	}

	void SetValue(int row, int col, T value)
	{
		if (row >= 0 && row < num_row && col >= 0 && col < num_col)
		{
			ptr[(num_col * row) + col] = value;
		}
	}

	const T& GetValue(int row, int col) const
	{
		if (row >= 0 && row < num_row && col >= 0 && col < num_col)
		{
			return ptr[(num_col * row) + col];
		}
		else
		{
			return 10000;
		}
	}

	Matrix Add(const Matrix& mx) const
	{
		assert(num_row == mx.num_row);
		assert(num_col == mx.num_col);

		Matrix temp(num_row, num_col);

		for (int i = 0; i < num_row * num_col; i++)
		{
			temp.ptr[i] = ptr[i] + mx.ptr[i];
		}

		return temp;
	}

	Matrix Transpose1() const
	{
		Matrix temp(num_col, num_row);
		
		int i = 0;
		for (int j = 0; i < num_col * num_row && j < num_col; j++)
		{
			for (int t = 0; i < num_col * num_row && t < num_row; t++)
			{
				temp.ptr[i] = ptr[num_col * t + j];
				i++;
			}
		}

		return temp;
	}
	// 0 1 2
	// 3 4 5
	// 6 7 8

	Matrix Transpose2() const
	{
		Matrix temp(num_col, num_row);
		
		for (int r = 0; r < num_row; r++)
		{
			for (int c = 0; c < num_col; c++)
			{
				temp.ptr[temp.num_col * c + r] = ptr[num_col * r + c];
			}
		}

		return temp;
	}

	Matrix Transpose3() const
	{
		Matrix temp(num_col, num_row);

		for (int r = 0; r < num_row; r++)
		{
			for (int c = 0; c < num_col; c++)
			{
				temp.SetValue(c, r, this->GetValue(r, c));
			}
		}

		return temp;
	}


	void print() const
	{
		int t = 0;
		for (int i = 0; i < num_row; i++)
		{
			for (int j = 0; j < num_col; j++)
			{
				if (t >= 0 && t < num_row * num_col)
				{
					std::cout << ptr[t] << " ";
					t++;
				}
			}
			std::cout << std::endl;
		}
	}

};