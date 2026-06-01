#include "Polynomial.h"

Polynomial::Polynomial(int max_degree)
{
	assert(max_degree >= 0);

	capacity = max_degree + 1;

	coeffs = new float[capacity];

	for (int i = 0; i < capacity; i++)
	{
		coeffs[i] = 0.0f;
	}
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->capacity = poly.capacity;
	this->coeffs = new float[capacity];

	for (int i = 0; i < capacity; i++)
	{
		coeffs[i] = poly.coeffs[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] coeffs;
}

int Polynomial::MaxDegree() 
{	
	int index = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (coeffs[i] != 0.0f)
		{
			index = i;
		}
	}
	return index;
}

void Polynomial::NewTerm(const float coef, const int exp)
{
	coeffs[exp] = coef;
}

Polynomial Polynomial::Add(const Polynomial& Poly)
{
	Polynomial Add_Sum{};

	for (int i = 0; i < capacity; i++)
	{
		Add_Sum.coeffs[i] = coeffs[i] + Poly.coeffs[i];
	}

	return Add_Sum;
}

// (1 + 2x + x^2) x (2 + 3x^2)
Polynomial Polynomial::Mult(const Polynomial& Poly)
{
	Polynomial temp;
	for (int i = 0; i < capacity; i++)
	{	
		if (coeffs[i] == 0.0f)
		{
			continue;
		}

		for (int j = 0; j < Poly.capacity; j++)
		{
			if (Poly.coeffs[j] == 0.0f)
			{
				continue;
			}

			temp.coeffs[i+j] += (this->coeffs[i] * Poly.coeffs[j]);
		}
	}
	return temp;
}

float power(float x, int exp)
{
	float result = 1;

	if (exp == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= exp ; i++)
		{
			result *= x;
		}
		return result;
	}
}

// 1 + x + x^2
float Polynomial::Eval(float x)
{
	float result = 0;

	for (int i = 0; i < capacity; i++)
	{
		result += (coeffs[i] * power(x, i));
	}
	return result;
}

void Polynomial::Print()
{	
	bool first_term = true;

	if (first_term == true)
	{
		std::cout << coeffs[0] << " ";
		first_term = false;
	}

	for (int i = 1; i < capacity; i++)
	{
		if (coeffs[i] != 0.0f)
		{
			std::cout << "+" << " " << coeffs[i] << "x^" << i << " ";
		}
	}
	std::cout << std::endl;
}