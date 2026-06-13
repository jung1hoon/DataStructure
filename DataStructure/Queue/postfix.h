#pragma once

#include "../shared/queue.h"
#include "../shared/stack.h"
#include <iostream>
#include <cassert>
#include <iomanip>

int prec(char c);
void InfixToPostfix(Queue<char>& infix, Queue<char>& postfix);
int EvalPostfix(Queue<char>& q);
