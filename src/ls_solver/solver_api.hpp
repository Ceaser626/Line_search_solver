#pragma once

#include <iostream>
#include "line_search.hpp"


void ls_set_default_settings(LsSettings* settings);
void ls_setup(LsSolver** solverp, int nvar);
int ls_solve(LsSolver *solver);
