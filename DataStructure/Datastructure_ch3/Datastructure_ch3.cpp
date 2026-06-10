#include "Maze.h"


using namespace std;


Stack<char> tower[3]; // 하노이의 탑 문제

void PrintTower()
{
	std::cout << "Tower" << std::endl;
	std::cout << "0 : ";
	tower[0].Print();
	std::cout << "1 : ";
	tower[1].Print();
	std::cout << "2 : ";
	tower[2].Print();
}

void MoveDisk(int from, int to)
{
	if (tower[from].IsEmpty())
	{
		std::cout << "Tower " << from << "is empty" << std::endl;

		return;
	}

	if (!tower[to].IsEmpty() && tower[to].Top() > tower[from].Top())
	{
		std::cout << "Can't place " << tower[from].Top() << " " << "on" << " " << tower[to].Top() << std::endl;
	}
	else
	{
		tower[to].push(tower[from].Top());
		tower[from].pop();

		PrintTower();
	}
}

void RecurMoveDisks(int n, int from, int temp, int to)
{
	if (n <= 0)
	{
		return;
	}

	RecurMoveDisks(n - 1, from, to, temp);

	MoveDisk(from, to);

	RecurMoveDisks(n - 1, temp, from, to);
}


int main()
{
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		tower[0].push('A' + i);
	}
	
	RecurMoveDisks(n, 0, 1, 2);




	return 0;
}
