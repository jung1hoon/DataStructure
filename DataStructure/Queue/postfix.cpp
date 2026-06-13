#include "../shared/queue.h"
#include "../shared/stack.h"


int prec(char c)
{
	if (c == '/' || c == '*')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void InfixToPostfix(Queue<char>& infix, Queue<char>& postfix)
{
	Stack<char> st;

	while (!infix.IsEmpty())
	{
		char c = infix.Front();
		infix.Dequeue();

		if (c >= '0' && c <= '9')
		{
			postfix.Enqueue(c);
		}
		else if(c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			while (!st.IsEmpty() && st.Top() != '(')
			{
				postfix.Enqueue(st.Top());
				st.pop();
			}

			st.pop();
		}
		else
		{
			while (!st.IsEmpty() && st.Top() != '(' && prec(st.Top()) >= prec(c))
			{
				postfix.Enqueue(st.Top());
				st.pop();
			}

			st.push(c);
		}
	}
	while (!st.IsEmpty())
	{
		postfix.Enqueue(st.Top());
		st.pop();
	}

}

int EvalPostfix(Queue<char>& q)
{
	Stack<int> st;

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			st.push(c - '0');
		}
		else
		{
			int oper2 = st.Top();
			st.pop();
			int oper1 = st.Top();
			st.pop();

			if (c == '+')
			{
				st.push(oper1 + oper2);
			}
			else if (c == '-')
			{
				st.push(oper1 - oper2);
			}
			else if (c == '*')
			{
				st.push(oper1 * oper2);
			}
			else if (c == '/')
			{
				st.push(oper1 / oper2);
			}
		}

	}
	return st.Top();
}