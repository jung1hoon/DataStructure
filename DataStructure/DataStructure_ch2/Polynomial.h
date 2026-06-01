#pragma once
#include <iostream>
#include <math.h>
#include <cassert>

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