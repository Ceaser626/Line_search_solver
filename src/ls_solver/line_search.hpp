#pragma once
#include "types.hpp"


void update_functionval(LsSolver *solver);
float update_functionval(LsSolver *solver, lsVector s);
void update_gradient(LsSolver *solver);
void backtrack(LsSolver *solver);
bool termination_condition(LsSolver *solver);
int solve(LsSolver *solver);
