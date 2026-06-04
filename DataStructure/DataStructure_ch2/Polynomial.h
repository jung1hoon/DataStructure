#pragma once
#include <iostream>
#include <math.h>
#include <cassert>
#include <algorithm>

class Polynomial
{
public:
	Polynomial(int max_degree = 100);

	Polynomial(const Polynomial& poly);

	~Polynomial();

	int MaxDegree();

	void NewTerm(const float coef, const int exp);

	Polynomial Add(const Polynomial& Poly);

	Polynomial Mult(const Polynomial& Poly);

	float Eval(float x);

	void Print();


private:
	int capacity = 0;
	float* coeffs = nullptr;
};

struct Term
{
	float coeffs = 0;
	int exp = 100;
};

class SparsePolynomial
{
	Term* ptr = nullptr;
	int capacity = 8;
	int num_term = 0;

public:
	SparsePolynomial(){}
	~SparsePolynomial()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
		}
	}

	void NewTerm(float coef, int exp);

	float Eval(float x);

	SparsePolynomial Add(const SparsePolynomial& poly);

	void Print();


};