#include "Maze.h"

using namespace std;


int main()
{
	

	Pos p1 = { 1,1 };
	Stack<Pos> p2;
	p2.push(p1);



	PrintMaze();

	//StackMaze(p2);
	RecurMaze(p1);

	PrintMaze();


	return 0;
}