#include <iostream>
#include "line_search.hpp"


void update_functionval(LsSolver *solver)
{
    solver->work->f = pow(solver->work->s(0) - 2, 4)
                    + pow(solver->work->s(0) - 2 * solver->work->s(1), 2);
}


float update_functionval(LsSolver *solver, lsVector s)
{
    double f = pow(s(0) - 2, 4)
             + pow(s(0) - 2 * s(1), 2);
    return f;
}


void update_gradient(LsSolver *solver)
{
   solver->work->g(0) = 4 * pow(solver->work->s(0) - 2, 3)
                            + 2 * (solver->work->s(0) - 2 * solver->work->s(1));
   solver->work->g(1) = -4 * (solver->work->s(0) - 2 * solver->work->s(1));
}


void backtrack(LsSolver *solver)
{
	solver->work->sfd = 0;
	solver->work->alpha = 1;
	solver->work->step = - solver->work->g;

    while(!solver->work->sfd)
        {
      		lsVector step_trail = solver->work->s + solver->work->alpha * solver->work->step;
			double f_new = update_functionval(solver, step_trail);

            double f_line = solver->work->f + solver->settings->coff_c * solver->work->alpha * solver->work->g.transpose() * solver->work->step;
            // double f_line = solver->work->f;

    		if (f_new <= f_line) {solver->work->sfd = 1;}
            else {solver->work->alpha *= solver->settings->coff_decay;}
    	}

    solver->work->s = solver->work->s + solver->work->alpha * solver->work->step;
}


bool termination_condition(LsSolver *solver)
{
    if(solver->work->g.norm() <= solver->settings->threshold)
    {
      return true;
    }
    return false;
}


int solve(LsSolver *solver)
{
    // Initialize variables
    solver->solution->iter = 0;
    solver->solution->solved = 0;
    solver->work->iter = 0;

    for (int i = 0; i < solver->settings->max_iter; i++)
    {
        update_functionval(solver);

        update_gradient(solver);

		backtrack(solver);

        std::cout << solver->work->iter << " iterations:" << std::endl;
        std::cout << "J = " << solver->work->f << std::endl;
        std::cout << "s = " << solver->work->s.transpose() << std::endl;
        std::cout << "ds norm: " << solver->work->g.norm() << std::endl;
        std::cout << "step: " << solver->work->step.transpose() << std::endl;
        std::cout << std::endl;

        solver->work->iter += 1;

        if (termination_condition(solver)){
			solver->work->status = 1;

            solver->solution->iter = solver->solution->iter;
            solver->solution->solved = 1;
            solver->solution->s = solver->work->s;
            return 0;
        }
    }

    return 1;
}
