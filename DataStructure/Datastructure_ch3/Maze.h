#pragma once
#include "../shared/stack.h"
#include <iostream>

inline constexpr int kNumRows = 10;
inline constexpr int kNumCols = 9;

extern char maze[kNumRows][kNumCols];

void PrintMaze();

struct Pos
{
	int row;
	int col;

	friend std::ostream& operator <<(std::ostream& out, const Pos& pos);
};

bool RecurMaze(Pos p);
bool StackMaze(Stack<Pos>& p);

