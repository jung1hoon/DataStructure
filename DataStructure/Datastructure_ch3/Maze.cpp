#include "Maze.h"

char maze[kNumRows][kNumCols] =
{
	{'1','1','1','1','1','1','1','1','1'},
	{'1','S','0','0','0','0','0','0','1'},
	{'1','1','1','1','0','1','0','1','1'},
	{'1','0','0','0','0','0','0','0','1'},
	{'1','0','1','1','1','1','1','1','1'},
	{'1','0','0','0','0','0','0','0','1'},
	{'1','1','1','1','1','0','1','1','1'},
	{'1','1','1','0','0','0','1','0','1'},
	{'1','0','0','0','0','0','0','G','1'},
	{'1','1','1','1','1','1','1','1','1'},
};

bool StackMaze(Stack<Pos>& p)
{	
	while (!p.IsEmpty())
	{
		if (maze[p.Top().row][p.Top().col] == 'G')
		{
			maze[p.Top().row][p.Top().col] = 'X';

			std::cout << "Found! : " << p.Top() << std::endl;;

			return true;
		}

		maze[p.Top().row][p.Top().col] = 'X';
		std::cout << p.Top() << std::endl;

		if (maze[p.Top().row - 1][p.Top().col] == '0' || maze[p.Top().row - 1][p.Top().col] == 'G')
		{
			p.push(Pos{ p.Top().row - 1 , p.Top().col });
		}
		else if (maze[p.Top().row + 1][p.Top().col] == '0' || maze[p.Top().row + 1][p.Top().col] == 'G')
		{
			p.push(Pos{ p.Top().row + 1 , p.Top().col });
		}
		else if (maze[p.Top().row][p.Top().col - 1] == '0' || maze[p.Top().row][p.Top().col - 1] == 'G')
		{
			p.push(Pos{ p.Top().row, p.Top().col - 1 });
		}
		else if (maze[p.Top().row][p.Top().col + 1] == '0' || maze[p.Top().row][p.Top().col + 1] == 'G')
		{
			p.push(Pos{ p.Top().row, p.Top().col + 1 });
		}
		else
		{
			p.pop();
		}
	}

	return false;

}


bool RecurMaze(Pos p)
{

	std::cout << p << std::endl;

	if (maze[p.row][p.col] == 'G')
	{
		std::cout << "Found! : " << p << std::endl;
		maze[p.row][p.col] = 'X';
		return true;
	}

	maze[p.row][p.col] = 'X';

	if (maze[p.row - 1][p.col] == '0' || maze[p.row - 1][p.col] == 'G')
	{
		if (RecurMaze({ p.row - 1, p.col })) { return true; };
	}
	if (maze[p.row + 1][p.col] == '0' || maze[p.row + 1][p.col] == 'G')
	{
		if (RecurMaze({ p.row + 1, p.col })) { return true; };
	}
	if (maze[p.row][p.col - 1] == '0' || maze[p.row][p.col - 1] == 'G')
	{
		if (RecurMaze({ p.row, p.col - 1 })) { return true; };
	}
	if (maze[p.row][p.col + 1] == '0'|| maze[p.row][p.col + 1] == 'G')
	{
		if (RecurMaze({ p.row, p.col + 1 })) { return true; };
	}
	
	return false;

	

}


void PrintMaze()
{
	for (int r = 0; r < kNumRows; r++)
	{
		for (int c = 0; c < kNumCols; c++)
		{
			std::cout << maze[r][c] << " ";
		}
		std::cout << std::endl;
	}
}

std::ostream& operator <<(std::ostream& out, const Pos& pos)
{
	out << "(" << pos.row << "," << pos.col << ")";
	return out;
}

