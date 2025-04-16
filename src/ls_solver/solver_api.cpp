#include <iostream>
#include "solver_api.hpp"
#include "solver_constants.hpp"

using namespace Eigen;


void ls_set_default_settings(LsSettings* settings)
{
    settings->coff_c = COFF_C;
    settings->coff_decay = COFF_DECAY;
    settings->threshold = THRESHOLD;
    settings->max_iter = MAX_ITER;
}


void ls_setup(LsSolver** solverp, int nvar)
{
    LsSolution *solution = new LsSolution();
    LsSettings *settings = new LsSettings();
    LsWorkspace *work = new LsWorkspace();
    LsSolver *solver = new LsSolver();

    solver->solution = solution;
    solver->settings = settings;
    solver->work = work;
    *solverp = solver;

    solution->iter = 0;
    solution->solved = 0;
    solution->s = lsVector::Zero(nvar, 1);

    ls_set_default_settings(settings);

    work->f = 0;
    work->s = lsVector::Zero(nvar, 1);
    work->g = lsVector::Zero(nvar, 1);
    work->alpha = 1;
    work->step = lsVector::Zero(nvar, 1);
    work->sfd = 0;
    work->status = 0;
    work->iter = 0;
}


int ls_solve(LsSolver *solver)
{
    return solve(solver);
}
