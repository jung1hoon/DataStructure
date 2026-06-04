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
	float result = 1.0f;

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
	float result = 0.0f;

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


//SparsePolynomial

void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f)
	{
		return;
	}

	if (num_term == 0)
	{
		ptr = new Term[capacity];

		ptr[0].coeffs = coef;
		ptr[0].exp = exp;

		num_term++;
		return;
	}


	for (int i = 0; i < num_term; i++)
	{
		if (ptr[i].exp == exp)
		{
			ptr[i].coeffs += coef;
			return;
		}
	}

	if (num_term >= capacity)
	{
		this->capacity = capacity * 2;

		if (capacity > num_term)
		{
			Term* new_ptr = new Term[capacity];

			for (int i = 0; i < num_term; i++)
			{
				new_ptr[i] = ptr[i];
			}

			if (ptr != nullptr)
			{
				delete[] ptr;
			}

			ptr = new_ptr;

			ptr[num_term].coeffs = coef;
			ptr[num_term].exp = exp;

			num_term++;
		}
		else
		{
			return;
		}
	}
	else
	{
		ptr[num_term].coeffs = coef;
		ptr[num_term].exp = exp;

		num_term++;
	}
	
	std::sort(ptr, ptr + num_term, [](const Term& a, const Term& b) {return a.exp < b.exp;});
}

float SparsePolynomial::Eval(float x)
{
	float result = 0.0f;

	for (int i = 0; i < num_term; i++)
	{
		result += ptr[i].coeffs * power(x, (ptr[i].exp));
	}

	return result;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	SparsePolynomial p;
	

	int i = 0, j = 0;
	while (i < num_term && j < poly.num_term)
	{
		if (ptr[i].exp == poly.ptr[j].exp)
		{
			float sum = ptr[i].coeffs + poly.ptr[j].coeffs;
			p.NewTerm(sum, ptr[i].exp);
			i++;
			j++;
		}
		else if (ptr[i].exp > poly.ptr[j].exp)
		{
			p.NewTerm(poly.ptr[j].coeffs, poly.ptr[j].exp);
			j++;
		}
		else
		{
			p.NewTerm(ptr[i].coeffs, ptr[i].exp);
			i++;
		}
	}

	for (; i < num_term; i++)
	{
		p.NewTerm(ptr[i].coeffs, ptr[i].exp);
	}

	for (; j < poly.num_term; j++)
	{
		p.NewTerm(poly.ptr[j].coeffs, poly.ptr[j].exp);
	}

	return p;
}

void SparsePolynomial::Print()
{
	if (num_term != 0)
	{
		for (int i = 0; i < num_term; i++)
		{
			if (i == 0 && ptr[i].exp == 0)
			{
				std::cout << ptr[i].coeffs << " ";
			}
			else if(i == 0 && ptr[i].exp != 0)
			{
				std::cout << ptr[i].coeffs << "x^" << ptr[i].exp << " ";
			}
			else
			{
				std::cout << "+" << " " << ptr[i].coeffs << "x^" << ptr[i].exp << " ";
			}
		}
	}
	else
	{
		std::cout << "Null" << std::endl;
	}
}
